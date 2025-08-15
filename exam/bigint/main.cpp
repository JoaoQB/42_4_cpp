#include <iostream>
#include "Bigint.hpp"

int main() {
    // ===== Constructor Tests =====
    Bigint empty;
    Bigint fromInt(12345);
    Bigint fromString("987654");
    Bigint copy(fromInt);
    Bigint test(0000000012);

    std::cout << "empty = " << empty << std::endl;
    std::cout << "fromInt = " << fromInt << std::endl;
    std::cout << "fromString = " << fromString << std::endl;
    std::cout << "copy(fromInt) = " << copy << std::endl;
    std::cout << "test = " << test << std::endl;

    Bigint a("4259");
    Bigint b(42);

    std::cout << "\n-- Addition --\n";
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a + 42 = " << a + 42 << std::endl;

    std::cout << "\n-- Subtraction --\n";
    std::cout << "fromString - fromInt = " << fromString - fromInt << std::endl;
    std::cout << "fromInt - b = " << fromInt - b << std::endl;

    std::string aString = "42";
    std::string bString = "42398";
    std::string zero = "0";

    std::cout << "Shift left tests:" << std::endl;
    std::cout << "42 << 3 = " << Bigint::shiftLeft(aString, 3) << std::endl;
    std::cout << "42 << 0 = " << Bigint::shiftLeft(aString, 0) << std::endl;
    std::cout << "0 << 5 = " << Bigint::shiftLeft(zero, 5) << std::endl;

    std::cout << "\nShift right tests:" << std::endl;
    std::cout << "42398 >> 3 = " << Bigint::shiftRight(bString, 3) << std::endl;
    std::cout << "42398 >> 0 = " << Bigint::shiftRight(bString, 0) << std::endl;
    std::cout << "42 >> 2 = " << Bigint::shiftRight(aString, 2) << std::endl;

    // std::cout << "\n-- Multiplication --\n";
    // std::cout << "b * 100 = " << b * Bigint(100) << std::endl;
    // std::cout << "a * b = " << a * b << std::endl;

    // std::cout << "\n-- Digit Shifting --\n";
    // std::cout << "b << 4 = " << (b << 4) << std::endl;
    // std::cout << "fromInt >> 2 = " << (fromInt >> 2) << std::endl;

    // Bigint shiftTest("123456");
    // shiftTest <<= 3;
    // std::cout << "shiftTest <<= 3 -> " << shiftTest << std::endl;
    // shiftTest >>= 4;
    // std::cout << "shiftTest >>= 4 -> " << shiftTest << std::endl;

    // std::cout << "\n-- Complex Expressions --\n";
    // std::cout << "((a + b) <<= 3) + 42 = "
    //           << ((a + b) <<= 3) + 42 << std::endl;

    // Bigint chain("999");
    // std::cout << "((chain * 2) >> 1) + (b << 2) = "
    //           << ((chain * Bigint(2)) >> 1) + (b << 2) << std::endl;

    // std::cout << "\n-- Stress Test (Large Numbers) --\n";
    // Bigint big1("999999999999999999999999999999999999999999");
    // Bigint big2("888888888888888888888888888888888888888888");

    // std::cout << "big1 + big2 = " << big1 + big2 << std::endl;
    // std::cout << "big1 * 42 = " << big1 * Bigint(42) << std::endl;

    // Bigint bigShift("123456789");
    // bigShift <<= 15;
    // std::cout << "bigShift <<= 15 = " << bigShift << std::endl;
    // bigShift >>= 10;
    // std::cout << "bigShift >>= 10 = " << bigShift << std::endl;

    // Bigint giantSum = ((big1 + big2) * Bigint(123456789)) << 5;
    // std::cout << "((big1 + big2) * 123456789) << 5 = " << giantSum << std::endl;

    return 0;
}
