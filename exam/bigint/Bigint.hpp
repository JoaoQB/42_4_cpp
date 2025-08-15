#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <string>
# include <iostream>
# include <sstream>

class Bigint {
	private:
		bool isOnlyDigits(const std::string& string);
		std::string normalize(const std::string& value);
		void padValues(std::string& value, std::string& otherValue);

	public:
		std::string rawValue;
		static const unsigned int base = 10;

		Bigint();
		Bigint(unsigned int value);
		Bigint(const std::string& value);
		Bigint(const Bigint& src);
		Bigint operator+(const Bigint& other);
		Bigint operator+(unsigned int value);
		Bigint operator-(const Bigint& other);
		Bigint operator-(unsigned int value);

		static std::string shiftLeft(const std::string& value,unsigned int n);
		static std::string shiftRight(const std::string& value,unsigned int n);
};

std::ostream& operator<<(std::ostream& out, Bigint& bigint);
std::ostream& operator<<(std::ostream& out, const Bigint& bigint);

#endif
