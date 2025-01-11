/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:42:39 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/11 12:20:24 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPtr = &str;
	std::string	&strRef = str;

	std::cout << "Memory address of the string variable (str): " << &str << std::endl;
	std::cout << "Memory address stored in the pointer (strPtr points to): " << strPtr << std::endl;
	std::cout << "Memory address accessed through the reference (strRef): " << &strRef << std::endl;

	std::cout << "Value of the string variable (str): " << str << std::endl;
	std::cout << "Value accessed through the pointer (*strPtr): " << *strPtr << std::endl;
	std::cout << "Value accessed through the reference (strRef): " << strRef << std::endl;
}
