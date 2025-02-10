/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:02 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/10 11:44:16 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/PrintBinary.hpp"

#include <limits>

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int main() {
	// Create an instance of PrintBinary
	PrintBinary pb; // Constructor should be called

	// Testing Fixed class with various constructors
	const Fixed fixedInt1(10); // Integer constructor
	const Fixed fixedInt2(5);
	const Fixed fixedFloat1(3.75f); // Float constructor
	const Fixed fixedFloat2(2.5f);

	// Testing arithmetic operations
	Fixed sum = fixedInt1 + fixedInt2; // 10 + 5
	Fixed difference = fixedInt1 - fixedFloat1; // 10 - 3.75
	Fixed product = fixedFloat1 * fixedFloat2; // 3.75 * 2.5
	Fixed quotient = fixedInt1 / fixedFloat2; // 10 / 2.5

	// Output results
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Difference: " << difference << std::endl;
	std::cout << "Product: " << product << std::endl;
	std::cout << "Quotient: " << quotient << std::endl;

	pb.printInt(sum.getRawBits());
	pb.printInt(sum.toInt());
	pb.printInt(difference.getRawBits());
	pb.printInt(difference.toFloat());
	pb.printInt(product.getRawBits());
	pb.printFloat(product.toFloat());
	pb.printInt(quotient.getRawBits());
	pb.printFloat(quotient.toInt());

	// Testing comparison operators
	std::cout << "Fixed Int1 > Fixed Int2: " << (fixedInt1 > fixedInt2) << std::endl; // true
	std::cout << "Fixed Float1 < Fixed Float2: " << (fixedFloat1 < fixedFloat2) << std::endl; // false
	std::cout << "Fixed Int1 == Fixed Int2: " << (fixedInt1 == fixedInt2) << std::endl; // false

	// Binary representation tests
	pb.printInt(42); // Print binary of integer 42
	pb.printFloat(3.14f); // Print binary of float 3.14

	// Testing min and max functions
	const Fixed& minValue = Fixed::min(fixedInt1, fixedInt2);
	const Fixed& maxValue = Fixed::max(fixedFloat1, fixedFloat2);

	std::cout << "Min: " << minValue << std::endl;
	std::cout << "Max: " << maxValue << std::endl;

	Fixed zero;
	Fixed nine(9);

	std::cout << "division by zero: " << nine / zero << std::endl;
	// Destructor will be called when instances go out of scope
	return 0;
}
