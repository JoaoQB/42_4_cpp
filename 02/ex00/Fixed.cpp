/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/16 16:51:53 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fracBits = 8;

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "Fixed Constructor Called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixedPoint(other.fixedPoint) {
	std::cout << "Fixed Copy Constructor Called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &other) {

}
