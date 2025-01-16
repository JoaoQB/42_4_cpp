/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:11 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/16 16:51:33 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	fixedPoint;
		static const int	fracBits;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed&	operator=(const Fixed &other);
		~Fixed();
};

#endif
