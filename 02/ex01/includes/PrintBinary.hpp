/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintBinary.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:31:40 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/21 15:52:24 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTBINARY_HPP
#define PRINTBINARY_HPP

#include "Fixed.hpp"
#include <bitset>
#include <cstring>

class PrintBinary {
	public:
		PrintBinary();
		~PrintBinary();
		void	printInt(const int i);
		void	printFloat(const float f);
};

#endif
