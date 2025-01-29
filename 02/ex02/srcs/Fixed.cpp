/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/29 17:47:43 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::fracBits = 8;

Fixed::Fixed() : value(0) {
	// std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(const int integer) {
	// std::cout << "Int Constructor Called" << std::endl;
	value = integer << fracBits;
}

Fixed::Fixed(const float floatingPoint) {
	// std::cout << "Float Constructor Called" << std::endl;
	value = (floatingPoint) * (1 << fracBits) + ((floatingPoint) >= 0 ? 0.5f : -0.5f);
}

Fixed::Fixed(const Fixed &other) {
	// std::cout << "Copy Constructor Called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	// std::cout << "Destructor Called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &other) {
	// std::cout << "Assignment Operator Called" << std::endl;
	if (this != &other) {
		this->value = other.value;
	}
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits() Called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits() Called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat(void) const {
	return (float(value) / float(1 << fracBits));
}

int	Fixed::toInt(void) const {
	return (value >> fracBits);
}

bool	Fixed::operator>(const Fixed &other) const{
	// std::cout << "Greater Than Operator Called" << std::endl;
	return (this->value > other.value);
}

bool	Fixed::operator<(const Fixed &other) const{
	// std::cout << "Smaller Than Operator Called" << std::endl;
	return (this->value < other.value);
}

bool	Fixed::operator>=(const Fixed &other) const{
	// std::cout << "Bigger or Equal Operator Called" << std::endl;
	return (this->value >= other.value);
}

bool	Fixed::operator<=(const Fixed &other) const{
	// std::cout << "Smaller or Equal Operator Called" << std::endl;
	return (this->value <= other.value);
}

bool	Fixed::operator==(const Fixed &other) const{
	// std::cout << "Is Equal Operator Called" << std::endl;
	return (this->value == other.value);
}

bool	Fixed::operator!=(const Fixed &other) const{
	// std::cout << "Is Different Operator Called" << std::endl;
	return (this->value != other.value);
}

Fixed	Fixed::operator+(const Fixed &other) const{
	// std::cout << "Addition Operator Called" << std::endl;
	Fixed	result;
	result.value = this->value + other.value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const{
	// std::cout << "Subtraction Operator Called" << std::endl;
	Fixed	result;
	result.value = this->value - other.value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const{
	// std::cout << "Multiplication Operator Called" << std::endl;
	Fixed	result;
	result.value = (this->value * other.value) >> fracBits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const{
	// std::cout << "Division Operator Called" << std::endl;
	Fixed	result;
	result.value = (this->value << fracBits) / other.value;
	return (result);
}

Fixed&	Fixed::operator++() {
	this->value += 1;
	return (*this);
}

Fixed&	Fixed::operator--() {
	this->value -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	old = *this;
	this->operator++();
	return (old);
}

Fixed	Fixed::operator--(int) {
	Fixed	old = *this;
	this->operator--();
	return (old);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b) {
	if (a == b) {
		return (a);
	}
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b) {
	if (a == b) {
		return (a);
	}
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b) {
	if (a == b) {
		return (a);
	}
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b) {
	if (a == b) {
		return (a);
	}
	return (a > b ? a : b);
}

std::ostream&	operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}
