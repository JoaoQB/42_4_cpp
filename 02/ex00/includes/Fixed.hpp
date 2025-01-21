/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:11 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/21 12:13:11 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	value;
		static const int	fracBits;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed&	operator=(const Fixed &other);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
