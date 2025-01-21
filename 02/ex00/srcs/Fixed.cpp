/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/21 12:16:17 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::fracBits = 8;

Fixed::Fixed() : value(0) {
	std::cout << "Fixed Point Constructor Called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Fixed Point Copy Constructor Called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed &other) {
	std::cout << "Fixed Point Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->value = other.value;
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Fixed Point Destructor Called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits() Called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits() Called" << std::endl;
	this->value = raw;
}
