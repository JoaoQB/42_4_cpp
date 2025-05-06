/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:41:09 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/06 23:01:25 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void ScalarConverter::printErr(const std::string& error) {
	std::cerr << error << std::endl;
}

std::string ScalarConverter::trimInput(const std::string& input) {
	if (input.empty()) {
		printErr("Empty Input");
		return ("");
	}
	const char* whitespace = " \t\v\r\n";
	std::size_t start = input.find_first_not_of(whitespace);
	if (start == std::string::npos) {
		printErr("Invalid Input: only whitespaces");
		return ("");
	}
	std::size_t end = input.find_last_not_of(whitespace);
	return (input.substr(start, end - start + 1));
}

bool ScalarConverter::isPseudoLiteral(const std::string& input) {
	static const std::string pseudoLiterals[] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"
	};
	const size_t size = sizeof(pseudoLiterals) / sizeof(pseudoLiterals[0]);
	for (size_t i = 0; i < size; ++i) {
		if (input == pseudoLiterals[i]) {
			return (true);
		}
	}
	return (false);
}

void ScalarConverter::printPseudoLiteral(const std::string& input) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (input == "-inff" || input == "+inff" || input == "nanf") {
		std::cout << "float: " << input << "\n";
		const std::string inputDouble = input.substr(0, input.size() - 1);
		std::cout << "double: " << inputDouble << std::endl;
	} else {
		const std::string inputFloat = input + "f";
		std::cout << "float: " << inputFloat << "\n";
		std::cout << "double: " << input << std::endl;
	}
}

LiteralType ScalarConverter::findType(const std::string& input) {
	if (input.size() == 1 && isprint(input[0]) && !isdigit(input[0])) {
		return (CHAR);
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
			if (hasDot) return (INVALID);
			hasDot = true;
		}
		else if (c == 'f') {
			if (hasF || i != input.size() - 1) return (INVALID);
			hasF = true;
		}
		else return (INVALID);
	}
	if (!hasDigit) return (INVALID);
	if (hasF) return (hasDot ? FLOAT : INVALID);
	if (hasDot) return (DOUBLE);
	return (INT);
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

void ScalarConverter::convert(const std::string &input) {
	std::string trimmedInput = trimInput(input);
	if (trimmedInput.empty()) {
		return ;
	}
	std::cout << trimmedInput << std::endl;
	if (isPseudoLiteral(trimmedInput)) {
		// std::cout << trimmedInput << std::endl;
		printPseudoLiteral(trimmedInput);
		return ;
	}
	switch (findType(input)) {
		case CHAR: convertChar(input); break;
		// case INT: convertInt(input); break;
		// case FLOAT: convertFloat(input); break;
		// case DOUBLE: convertDouble(input); break;
		default: printErr("Invalid Input");
	}
}
