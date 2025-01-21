/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:02 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/21 16:53:25 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/PrintBinary.hpp"

#include <limits>

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}

// int main() {
// 	PrintBinary printer;
// 	Fixed a;
// 	Fixed b(56);
// 	Fixed c(26.5f);
// 	Fixed d(c);

// 	std::cout << "a (default): " << a << " as float, raw bits: " << a.getRawBits() << std::endl;
// 	std::cout << "b (int 56): " << b << " as float, raw bits: " << b.getRawBits() << std::endl;
// 	std::cout << "c (float 26.5): " << c << " as float, raw bits: " << c.getRawBits() << std::endl;
// 	std::cout << "d (copy of c): " << d << " as float, raw bits: " << d.getRawBits() << std::endl;

// 	std::cout << "a as int: " << a.toInt() << std::endl;
// 	std::cout << "b as int: " << b.toInt() << std::endl;
// 	std::cout << "c as int: " << c.toInt() << std::endl;
// 	std::cout << "d as int: " << d.toInt() << std::endl;

// 	printer.printInt(a.getRawBits());
// 	printer.printInt(a.toInt());
// 	printer.printInt(b.getRawBits());
// 	printer.printInt(b.toInt());
// 	printer.printInt(c.getRawBits());
// 	printer.printFloat(c.toFloat());
// 	printer.printInt(d.getRawBits());
// 	printer.printFloat(d.toFloat());

// 	b = Fixed(-56);
// 	c = Fixed(-26.5f);

// 	std::cout << "b (int 56): " << b << " as float, raw bits: " << b.getRawBits() << std::endl;
// 	std::cout << "c (float 26.5): " << c << " as float, raw bits: " << c.getRawBits() << std::endl;

// 	std::cout << "b as int: " << b.toInt() << std::endl;
// 	std::cout << "c as int: " << c.toInt() << std::endl;

// 	printer.printInt(b.getRawBits());
// 	printer.printInt(b.toInt());
// 	printer.printInt(c.getRawBits());
// 	printer.printFloat(c.toFloat());

// 	return 0;
// }
