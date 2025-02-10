/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:13:25 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/10 14:33:23 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Constructor called with name: ";
	std::cout << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.name) {
	std::cout << "ScavTrap Copy Constructor called for: ";
	std::cout << other.name << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called for: ";
	std::cout << this->name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap Equal Assignment Operator Called" << std::endl;
	std::cout << this->name << " = " << other.name << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (this->energyPoints == 0) {
		std::cout << this->name << ": \"Uh-oh! No energy?! ";
		std::cout << "That’s... bad, right? Do I punch now?\"" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << this->name << ": \"RAAAAH! TAKE THAT, " << target << "!\" *SMASH SMASH* ";
	std::cout << "(Hit for " << this->attackDamage << " damage!)\n";
	std::cout << "Energy left: " << this->energyPoints;
	std::cout << ". Probably enough for a few more swings!" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " in Gate Keeper mode! ";
	std::cout << "Nothing gets past me! Unless... wait, was I supposed to stop that guy?" << std::endl;
}
