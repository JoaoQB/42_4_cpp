/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:25:23 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/12 19:04:03 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
	// std::cout << this->name << " : is born, with weapon: ";
	// std::cout << this->weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	// std::cout << this->name << " : dies, along his weapon: ";
	// std::cout << this->weapon.getType() << std::endl;
}

void	HumanA::attack() {
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}
