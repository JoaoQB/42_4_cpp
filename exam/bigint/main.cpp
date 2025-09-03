//
//
//

#include <iostream>
#include "Bigint.hpp"

int main() {
	// ===== Constructor Tests =====
	Bigint empty;
	Bigint fromInt(12345);
	Bigint fromString("987654");
	Bigint copy(fromInt);
	Bigint test(0000000012);
	Bigint a("4257");
	Bigint b(42);
	Bigint shiftTest("123456");

	std::cout << "empty = " << empty << std::endl;
	std::cout << "fromInt = " << fromInt << std::endl;
	std::cout << "fromString = " << fromString << std::endl;
	std::cout << "copy(fromInt) = " << copy << std::endl;
	std::cout << "test = " << test << std::endl;
	std::cout << "test = " << test << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "shiftTest = " << shiftTest << std::endl;

	// ===== Addition =====
	std::cout << "\n-- Addition --\n";
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a += b = " << (a += b) << std::endl;
	std::cout << "a + 42 = " << a + 42 << std::endl;
	std::cout << "a += 42 = " << (a += 42) << std::endl;

	std::cout << "empty = " << empty << std::endl;
	std::cout << "fromInt = " << fromInt << std::endl;
	std::cout << "fromString = " << fromString << std::endl;
	std::cout << "copy(fromInt) = " << copy << std::endl;
	std::cout << "test = " << test << std::endl;
	std::cout << "test = " << test << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "shiftTest = " << shiftTest << std::endl;

	// ===== Digit Shifting =====
	std::cout << "\n-- Digit Shifting --\n";
	std::cout << "b << 4 = " << (b << 4) << std::endl;
	std::cout << "fromInt >> 2 = " << (fromInt >> 2) << std::endl;

	shiftTest <<= 3;
	std::cout << "shiftTest <<= 3 -> " << shiftTest << std::endl;
	shiftTest >>= 4;
	std::cout << "shiftTest >>= 4 -> " << shiftTest << std::endl;

	// Test with Bigint as shift amount
	std::cout << "(a >>= (Bigint)2) -> " << (a >>= (Bigint)2) << std::endl;

	std::cout << "empty = " << empty << std::endl;
	std::cout << "fromInt = " << fromInt << std::endl;
	std::cout << "fromString = " << fromString << std::endl;
	std::cout << "copy(fromInt) = " << copy << std::endl;
	std::cout << "test = " << test << std::endl;
	std::cout << "test = " << test << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "shiftTest = " << shiftTest << std::endl;

	// ===== Comparisons =====
	// std::cout << "\n-- Comparisons --\n";
	// std::cout << "fromInt == copy: " << (fromInt == copy) << std::endl;
	// std::cout << "fromInt != b: " << (fromInt != b) << std::endl;
	// std::cout << "fromInt > b: " << (fromInt > b) << std::endl;
	// std::cout << "fromInt < fromString: " << (fromInt < fromString) << std::endl;
	// std::cout << "fromInt <= copy: " << (fromInt <= copy) << std::endl;
	// std::cout << "fromInt >= copy: " << (fromInt >= copy) << std::endl;

	// ===== Complex Expression =====
	std::cout << "\n-- Complex Expressions --\n";
	std::cout << "((a + b) << 3) + 42 = " << ((a + b) << 3) + 42 << std::endl;

	return 0;
}
