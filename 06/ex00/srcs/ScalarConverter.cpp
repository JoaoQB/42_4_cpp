/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:41:09 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/08 17:52:54 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

std::string ScalarConverter::trimInput(const std::string& input) {
	if (input.empty()) {
		throw std::invalid_argument("Empty Input");
	}
	if (input.size() == 1 && isprint(input[0])) {
		return input;
	}
	const char* whitespace = " \t\v\r\n";
	std::size_t start = input.find_first_not_of(whitespace);
	if (start == std::string::npos) {
		throw std::invalid_argument("Invalid Input");
	}
	std::size_t end = input.find_last_not_of(whitespace);
	return input.substr(start, end - start + 1);
}

bool ScalarConverter::isPseudoLiteral(const std::string& input) {
	static const std::string pseudoLiterals[] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"
	};
	const size_t size = sizeof(pseudoLiterals) / sizeof(pseudoLiterals[0]);
	for (size_t i = 0; i < size; ++i) {
		if (input == pseudoLiterals[i]) {
			return true;
		}
	}
	return false;
}

void ScalarConverter::printPseudoLiteral(const std::string& input) {
	const bool isFloat = (input == "-inff" || input == "+inff" || input == "nanf");
	const std::string floatPart = isFloat ? input : input + 'f';
	const std::string doublePart = isFloat ? input.substr(0, input.size() - 1) : input;

	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << floatPart << "\n";
	std::cout << "double: " << doublePart << "\n";
}

LiteralType ScalarConverter::findType(const std::string& input) {
	if (input.size() == 1 && isprint(input[0]) && !isdigit(input[0])) {
		return CHAR;
	}
	bool hasDot = false;
	bool hasF = false;
	bool hasDigit = false;
	size_t i = (input[0] == '-' || input[0] == '+') ? 1 : 0;
	for (; i < input.size(); ++i) {
		char c = input[i];
		if (isdigit(c)) {
			hasDigit = true;
		}
		else if (c == '.') {
			if (hasDot) return INVALID;
			hasDot = true;
		}
		else if (c == 'f') {
			if (hasF || i != input.size() - 1) return INVALID;
			hasF = true;
		}
		else return INVALID;
	}
	if (!hasDigit) return INVALID;
	if (hasF) return hasDot ? FLOAT : INVALID;
	if (hasDot) return DOUBLE;
	return INT;
}

bool ScalarConverter::hasFloatSuffix(const std::string& input) {
	return !input.empty() && input[input.size() - 1] == 'f';
}

void ScalarConverter::printCharFromDouble(double number) {
	if (number > CHAR_MAX || number < CHAR_MIN) {
		std::cout << "char: impossible\n";
		return;
	}
	char c = static_cast<char>(number);
	std::cout << "char: ";
	if (isprint(c)) {
		std::cout << "'" << c << "'\n";
	} else {
		std::cout << "Non displayable\n";
	}
}


void ScalarConverter::convertChar(const std::string& input) {
	char c = input[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

void ScalarConverter::convertDouble(const std::string& input) {
	const std::string numericPart = hasFloatSuffix(input)
		? input.substr(0, input.size() - 1)
		: input;

	std::istringstream iss(numericPart);
	double value;

	iss >> value;
	if (iss.fail() || !iss.eof()) {
		throw std::invalid_argument("Failed to convert");
	}

	printCharFromDouble(value);

	if (value < INT_MIN || value > INT_MAX) {
		std::cout << "int: impossible\n";
	} else {
		const int intValue = static_cast<int>(value);
		std::cout << "int: " << intValue << "\n";
	}

	float floatValue = static_cast<float>(value);
	double intPart = 0.0;
	const bool isInteger = (modf(value, &intPart) == 0.0);
	std::cout << "float: " << floatValue << (isInteger ? ".0f\n" : "f\n");
	std::cout << "double: " << value << (isInteger ? ".0\n" : "\n");
}

void ScalarConverter::convert(const std::string& input) {
	try {
		std::string trimmedInput = trimInput(input);

		if (isPseudoLiteral(trimmedInput)) {
			printPseudoLiteral(trimmedInput);
			return;
		}

		switch (findType(trimmedInput)) {
			case CHAR: convertChar(trimmedInput); break;
			case INVALID: throw std::invalid_argument("Invalid Input");
			default: convertDouble(trimmedInput);
		}
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
