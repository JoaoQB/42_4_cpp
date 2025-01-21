/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintBinary.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:07:29 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/21 15:52:06 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PrintBinary.hpp"

PrintBinary::PrintBinary() {
	std::cout << "PrintBinary Constructor Called" << std::endl;
}

PrintBinary::~PrintBinary() {
	std::cout << "PrintBinary Destructor Called" << std::endl;
}

void	PrintBinary::printInt(const int i) {
	std::cout << "Binary representation of " << i << " (int): "
			<< std::bitset<32>(i) << std::endl; // 32 bits for int
}

void	PrintBinary::printFloat(const float f) {
	unsigned int floatAsInt;
	std::memcpy(&floatAsInt, &f, sizeof(float));
	std::cout << "Binary representation of " << f << " (float): "
			<< std::bitset<32>(floatAsInt) << std::endl; // 32 bits for float
}
