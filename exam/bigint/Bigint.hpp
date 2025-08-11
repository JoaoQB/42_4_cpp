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

		Bigint();
		Bigint(unsigned int value);
		Bigint(const std::string& value);
		Bigint& operator+(const Bigint& other);
		Bigint& operator+(unsigned int value);
};

std::ostream& operator<<(std::ostream& out, Bigint& bigint);

#endif
