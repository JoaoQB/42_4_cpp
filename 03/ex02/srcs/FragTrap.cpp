/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:57:44 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/10 16:11:59 by jqueijo-         ###   ########.fr       */
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

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name) {
	std::cout << "FragTrap Copy Constructor called for: ";
	std::cout << other.name << std::endl;
	*this = other;
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
	std::cout << "FRAGTRAP " << this->name;
	std::cout << ": \"Alright, who's ready for a high five? ";
	std::cout << "No one? Fine, I'll high five myself... *clap*\"";
	std::cout << std::endl;
}
