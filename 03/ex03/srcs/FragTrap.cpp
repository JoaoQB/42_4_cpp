/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:57:44 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/12 14:58:04 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Constructor called with name: ";
	std::cout << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap Copy Constructor called. Copy: ";
	std::cout << other.name << " into: " << this->name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called for: ";
	std::cout << this->name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap Equal Assignment Operator Called" << std::endl;
	std::cout << this->name << " = " << other.name << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}


void	FragTrap::highFivesGuys(void) {
	if (this->hitPoints <= 0) {
		std::cout << this->name << ": \"Dead again??? ";
		std::cout << "Sorry buddies, no high fives\"" << std::endl;
		return ;
	}
	if (this->energyPoints == 0) {
		std::cout << this->name << ": \"No energy again?! ";
		std::cout << "Sorry buddies, no high fives\"" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "FRAGTRAP " << this->name;
	std::cout << ": \"Alright, who's ready for a high five? ";
	std::cout << "No one? Fine, I'll high five myself... *clap*\"";
}
