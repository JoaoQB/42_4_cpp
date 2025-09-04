//
//
//

#include "Bigint.hpp"

Bigint::Bigint() : rawValue("0") {
}

Bigint::Bigint(const std::string& value) {
	if (isOnlyDigits(value)) {
		rawValue = normalize(value);
	} else {
		rawValue = "0";
		std::cerr << "Bigint string constructor has non digits passed\n";
	}
}

Bigint::Bigint(unsigned int value) {
	std::ostringstream oss;
	oss << value;
	std::string result = oss.str();
	rawValue = result;
}

Bigint::Bigint(const Bigint& src) : rawValue(src.rawValue) {
}

Bigint::~Bigint() {
}

Bigint& Bigint::operator=(const Bigint& other) {
	if (this != &other) {
		rawValue = other.rawValue;
	}
	return *this;
}

Bigint& Bigint::operator=(unsigned int integer) {
	Bigint other(integer);
	*this = other;
	return *this;
}

Bigint Bigint::operator+(const Bigint& other) const {
	std::string a = this->rawValue;
	std::string b = other.rawValue;
	padValues(a, b);
	std::string sum = sumValues(a, b);
	Bigint result(sum);

	return result;
}

Bigint Bigint::operator+(unsigned int integer) const {
	Bigint other(integer);
	Bigint result = *this + other;

	return result;
}

Bigint& Bigint::operator+=(const Bigint& other) {
	std::string a = this->rawValue;
	std::string b = other.rawValue;
	padValues(a, b);
	rawValue = sumValues(a, b);

	return *this;
}

Bigint& Bigint::operator+=(unsigned int integer) {
	Bigint other(integer);
	*this += other;

	return *this;
}

Bigint Bigint::operator++(int) {
	Bigint before(*this);
	*this += 1;
	return before;
}

Bigint& Bigint::operator++() {
	*this += 1;

	return *this;
}

Bigint Bigint::operator<<(unsigned int integer) const {
	std::string resultString(rawValue);
	resultString.append(integer, '0');
	Bigint result(resultString);

	return result;
}

Bigint Bigint::operator<<(const Bigint& other) const {
	unsigned int otherValue = std::atoi(other.rawValue.c_str());
	Bigint result = *this << otherValue;
	return result;
}

Bigint& Bigint::operator<<=(unsigned int integer) {
	rawValue.append(integer, '0');

	return *this;
}

Bigint& Bigint::operator<<=(const Bigint& other) {
	*this = *this << other;
	return *this;
}

Bigint Bigint::operator>>(unsigned int integer) const {
	std::string resultString(rawValue);
	unsigned int size = resultString.size();
	if (integer >= size) {
		resultString = "0";
	} else {
		unsigned int difference = size - integer;
		resultString = resultString.substr(0, difference);
	}
	Bigint result(resultString);

	return result;
}

Bigint Bigint::operator>>(const Bigint& other) const {
	unsigned int otherValue = std::atoi(other.rawValue.c_str());
	Bigint result = *this >> otherValue;

	return result;
}

Bigint& Bigint::operator>>=(unsigned int integer) {
	*this = *this >> integer;
	return *this;
}

Bigint& Bigint::operator>>=(const Bigint& other) {
	*this = *this >> other;

	return *this;
}

bool Bigint::operator>(const Bigint& other) const {
	const int sizeA = this->rawValue.size();
	const int sizeB = other.rawValue.size();
	if (sizeA != sizeB) {
		return sizeA > sizeB;
	}
	return rawValue > other.rawValue;
}

bool Bigint::operator<(const Bigint& other) const {
	return other > *this;
}

bool Bigint::operator==(const Bigint& other) const {
	return rawValue == other.rawValue;
}

bool Bigint::operator!=(const Bigint& other) const {
	return !(*this == other);
}

bool Bigint::operator>=(const Bigint& other) const {
	return *this > other || *this == other;
}

bool Bigint::operator<=(const Bigint& other) const {
	return *this < other || *this == other;
}

bool Bigint::isOnlyDigits(const std::string& string) {
	if (string.empty()) {
		return false;
	}
	for (
		std::string::const_iterator it = string.begin();
		it != string.end();
		++it
	) {
		if (!std::isdigit(*it)) {
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

void Bigint::padValues(std::string&a, std::string& b) {
	unsigned int sizeA = a.size();
	unsigned int sizeB = b.size();
	if (sizeA == sizeB) {
		return ;
	}
	std::string& bigger = sizeA > sizeB ? a : b;
	std::string& smaller = sizeA > sizeB ? b : a;
	unsigned int difference = bigger.size() - smaller.size();
	smaller.insert(0, difference, '0');
	return;
}

std::string Bigint::sumValues(const std::string& a, const std::string& b) {
	int carry = 0;
	std::string result;
	for (unsigned int i = a.size(); i > 0; --i) {
		unsigned int index = i - 1;
		unsigned int left = a[index] - '0';
		unsigned int right = b[index] - '0';
		unsigned int sum = left + right + carry;
		unsigned int digit = sum % 10;
		carry = sum / 10;
		result.insert(result.begin(), digit + '0');
	}
	if (carry > 0) {
		result.insert(result.begin(), carry + '0');
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, Bigint& src) {
	out << src.rawValue;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Bigint& src) {
	out << src.rawValue;
	return out;
}
