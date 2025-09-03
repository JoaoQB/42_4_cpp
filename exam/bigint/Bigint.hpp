//
//
//

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Bigint {
private:

	static bool isOnlyDigits(const std::string& string);
	static std::string normalize(const std::string& value);
	static void padValues(std::string&a, std::string& b);
	static std::string sumValues(const std::string& a, const std::string& b);

public:
	std::string rawValue;

	Bigint();
	Bigint(std::string value);
	Bigint(unsigned int value);
	Bigint(const Bigint& src);
	~Bigint();
	Bigint& operator=(const Bigint& other);
	Bigint& operator=(unsigned int integer);

	Bigint operator+(const Bigint& other) const;
	Bigint operator+(unsigned int integer) const;
	Bigint& operator+=(const Bigint& other);
	Bigint& operator+=(unsigned int integer);

	Bigint operator<<(unsigned int integer) const;
	Bigint operator<<(const Bigint& other) const;
	Bigint& operator<<=(unsigned int integer);
	Bigint& operator<<=(const Bigint& other);

	Bigint operator>>(unsigned int integer) const;
	Bigint operator>>(const Bigint& other) const;
	Bigint& operator>>=(unsigned int integer);
	Bigint& operator>>=(const Bigint& other);
};

std::ostream& operator<<(std::ostream& out, Bigint& src);
std::ostream& operator<<(std::ostream& out, const Bigint& src);
