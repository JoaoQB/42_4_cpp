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
	if (isOnlyDigits(value)) {
		this->rawValue = normalize(value);
	} else {
		this->rawValue = "0";
		std::cerr << "String constructor contained non-digits: "
			<< value << ".\nFalling back to 0.\n";
	}
}

Bigint& Bigint::operator+(const Bigint& other) {
	std::string thisValue = this->rawValue;
	std::string otherValue = other.rawValue;

	padValues(thisValue, otherValue);
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
	if (valueLen == valueLen) {
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

std::ostream& operator<<(std::ostream& out, Bigint& bigint) {
	out << bigint.rawValue;
	return out;
}

