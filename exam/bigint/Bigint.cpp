/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:50:10 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/08/10 13:39:08 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bigint.hpp"

Bigint::Bigint() : rawValue("0") {

	std::cout << "Bigint Constructor called with empty value: "
		<< rawValue << std::endl;
}

Bigint::Bigint(unsigned int value) : rawValue() {
	std::ostringstream outss;
	outss << value;
	rawValue = outss.str();
	rawValue = normalize(rawValue);

	std::cout << "BigInt Constructor called with int value: "
			<< rawValue << std::endl;
}

Bigint::Bigint(const std::string& value) {
	std::cout << "BigInt Constructor called with string value: "
		<< value << std::endl;
	if (isOnlyDigits(value)) {
		this->rawValue = normalize(value);
	} else {
		this->rawValue = "0";
		std::cerr << "String constructor contained non-digits: "
			<< value << ".\nFalling back to 0.\n";
	}
}

Bigint::Bigint(const Bigint& src) : rawValue(src.rawValue) {
	std::cout << "BigInt Copy Constructor called with src value: "
		<< rawValue << std::endl;
}

Bigint Bigint::operator+(const Bigint& other) {
	std::string thisValue = this->rawValue;
	std::string otherValue = other.rawValue;

	std::cout << "Values before padding:\n" << *this << "\n" << other << "\n";
	padValues(thisValue, otherValue);
	std::cout << "Values after padding:\n" << thisValue << "\n" << otherValue << "\n";

	std::string resultString;
	unsigned int carry = 0;
	for (std::string::size_type i = otherValue.size(); i > 0; --i) {
		unsigned int index = i - 1;
		unsigned int thisDigit = thisValue[index] - '0';
		unsigned int otherDigit = otherValue[index] - '0';
		unsigned int sum = thisDigit + otherDigit + carry;
		unsigned int digit = sum % base;
		carry = sum / base;
		resultString.insert(resultString.begin(), digit + '0');
	}
	if (carry > 0) {
		resultString.insert(resultString.begin(), carry + '0');
	}
	Bigint result(resultString);
	return result;
}

Bigint Bigint::operator+(unsigned int value) {
	std::string thisValue = this->rawValue;
	Bigint other(value);
	std::string otherValue = other.rawValue;

	std::cout << "Values before padding:\n" << *this << "\n" << other << "\n";
	padValues(thisValue, otherValue);
	std::cout << "Values after padding:\n" << thisValue << "\n" << otherValue << "\n";

	std::string resultString;
	unsigned int carry = 0;
	for (std::string::size_type i = otherValue.size(); i > 0; --i) {
		unsigned int index = i - 1;
		unsigned int thisDigit = thisValue[index] - '0';
		unsigned int otherDigit = otherValue[index] - '0';
		unsigned int sum = thisDigit + otherDigit + carry;
		unsigned int digit = sum % base;
		carry = sum / base;
		resultString.insert(resultString.begin(), digit + '0');
	}
	if (carry > 0) {
		resultString.insert(resultString.begin(), carry + '0');
	}
	Bigint result(resultString);
	return result;
}

Bigint Bigint::operator-(const Bigint& other) {
	std::string thisValue = this->rawValue;
	std::string otherValue = other.rawValue;

	if (thisValue.length() < otherValue.length()) {
		return Bigint('0');
	}

	std::cout << "Values before padding:\n" << *this << "\n" << other << "\n";
	padValues(thisValue, otherValue);
	std::cout << "Values after padding:\n" << thisValue << "\n" << otherValue << "\n";

	std::string resultString;
	unsigned int borrow = 0;
	for (std::string::size_type i = otherValue.size(); i > 0; --i) {
		unsigned int index = i - 1;
		int thisDigit = thisValue[index] - '0';
		int otherDigit = otherValue[index] - '0';
		int diff = thisDigit - otherDigit - borrow;
		if (diff < 0) {
			diff += base;
			borrow = 1;
		} else {
			borrow = 0;
		}
		resultString.insert(resultString.begin(), diff + '0');
	}
	Bigint result(resultString);
	return result;
}

Bigint Bigint::operator-(unsigned int value) {
	std::string thisValue = this->rawValue;
	Bigint other(value);
	std::string otherValue = other.rawValue;

	if (thisValue.length() < otherValue.length()) {
		return Bigint('0');
	}

	std::cout << "Values before padding:\n" << *this << "\n" << other << "\n";
	padValues(thisValue, otherValue);
	std::cout << "Values after padding:\n" << thisValue << "\n" << otherValue << "\n";

	std::string resultString;
	unsigned int borrow = 0;
	for (std::string::size_type i = otherValue.size(); i > 0; --i) {
		unsigned int index = i - 1;
		int thisDigit = thisValue[index] - '0';
		int otherDigit = otherValue[index] - '0';
		int diff = thisDigit - otherDigit - borrow;
		if (diff < 0) {
			diff += base;
			borrow = 1;
		} else {
			borrow = 0;
		}
		resultString.insert(resultString.begin(), diff + '0');
	}
	Bigint result(resultString);
	return result;
}

bool Bigint::isOnlyDigits(const std::string& string) {
	if (string.empty()) {
		return false;
	}
	for (std::string::size_type i = 0; i < string.size(); ++i) {
		if (!std::isdigit(string[i])) {
			return false;
		}
	}
	return true;
}

std::string Bigint::normalize(const std::string& value) {
	std::string::size_type firstNonZero = value.find_first_not_of('0');
	if (firstNonZero == std::string::npos) {
		return "0";
	}
	return value.substr(firstNonZero);
}

void Bigint::padValues(std::string& value, std::string& otherValue) {
	std::string::size_type valueLen = value.length();
	std::string::size_type otherValueLen = otherValue.length();
	if (valueLen == otherValueLen) {
		return ;
	}
	std::string& bigger = valueLen > otherValueLen
			? value
			: otherValue;
	std::string& smaller = valueLen > otherValueLen
			? otherValue
			: value;
	std::string::size_type difference = bigger.length() - smaller.length();
	smaller.insert(0, difference, '0');
}

std::string Bigint::shiftLeft(const std::string& value, unsigned int n) {
	if (value == "0" || n == 0) {
		return value;
	}
	std::string result(value);
	result.append(n, '0');
	return result;
}

std::string Bigint::shiftRight(const std::string& value, unsigned int n) {
	if (value.length() <= n) {
		return "0";
	}
	std::string result = value.substr(0, value.length() - n);
	return result;
}

std::ostream& operator<<(std::ostream& out, Bigint& bigint) {
	out << bigint.rawValue;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Bigint& bigint) {
	out << bigint.rawValue;
	return out;
}
