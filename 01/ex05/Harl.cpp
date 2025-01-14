/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:44:50 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/14 20:47:11 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Harl constructed" << std::endl;
	funcArray[0] = &Harl::debug;
	funcArray[1] = &Harl::info;
	funcArray[2] = &Harl::warning;
	funcArray[3] = &Harl::error;
	funcNames[0] = "DEBUG";
	funcNames[1] = "INFO";
	funcNames[2] = "WARNING";
	funcNames[3] = "ERROR";
}

Harl::~Harl() {
	std::cout << "Harl destroyed" << std::endl;
}

void	Harl::complain(std::string level) {
	for (int i=0; i < N_FUNC; i++) {
		if (level == funcNames[i]) {
			(this->*funcArray[i])();
			return ;
		}
	}
	std::cout << "You can't even complaint nowadays!" << std::endl;
}

void	Harl::debug(void) {
	std::cout << "Debug: Do I really have to debug? Oh man!!! Bloody hell!!!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "Info: Do I really have to inform? Oh man!!! Bloody hell!!!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "Warning: Do I really have to warn? Oh man!!! Bloody hell!!!" << std::endl;
}

void	Harl::error(void) {
	std::cout << "Error: I had enough!" << std::endl;
}
