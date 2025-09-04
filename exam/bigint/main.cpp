//
//
//

#include <iostream>
#include "Bigint.hpp"

int main(void)
{
	const Bigint a(42);
	Bigint b(21), c, d(1337), e(d);

	// base test
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a + c = " << a + c << std::endl;
	std::cout << "(c += a) = " << (c += a) << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;

	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << ", d: " << d << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= (const Bigint)2) << ", d: " << d << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "(d < a) = " << (d < a) << std::endl;
	std::cout << "(d > a) = " << (d > a) << std::endl;
	std::cout << "(d == d) = " << (d == d) << std::endl;
	std::cout << "(d != a) = " << (d != a) << std::endl;
	std::cout << "(d <= a) = " << (d <= a) << std::endl;
	std::cout << "(d >= a) = " << (d >= a) << std::endl;

	Bigint x(12345678); Bigint y(5);
	std::cout << "(x << y) = " << (x << y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	std::cout << "x= " << (x <<= 5) << ", y= " << (y <<= 12) << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	return (0);
}
