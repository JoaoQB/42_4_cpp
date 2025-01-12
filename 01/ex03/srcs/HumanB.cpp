/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:25:32 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/12 19:05:10 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
	// std::cout << this->name << " : is born, without weapon." << std::endl;
}

HumanB::~HumanB() {
	// if (weapon) {
	// 	std::cout << this->name << " : dies, along his weapon: ";
	// 	std::cout << this->weapon->getType() << std::endl;
	// } else {
	// 	std::cout << this->name << " : dies, without a weapon." << std::endl;
	// }
}

void	HumanB::attack() {
	if (weapon) {
		std::cout << this->name << " attacks with their ";
		std::cout << this->weapon->getType() << std::endl;
	} else {
		std::cout << name << " attacks with their imagination" << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}
