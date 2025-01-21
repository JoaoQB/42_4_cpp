/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/21 16:18:22 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::fracBits = 8;

Fixed::Fixed() : value(0) {
	std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int Constructor Called" << std::endl;
	value = integer << fracBits;
}

Fixed::Fixed(const float floatingPoint) {
	std::cout << "Float Constructor Called" << std::endl;
	value = (floatingPoint) * (1 << fracBits) + ((floatingPoint) >= 0 ? 0.5f : -0.5f);
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy Constructor Called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed &other) {
	std::cout << "Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->value = other.value;
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor Called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits() Called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits() Called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat(void) const {
	return (float(value) / float(1 << fracBits));
}

int	Fixed::toInt(void) const {
	return (value >> fracBits);
}

std::ostream&	operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}
