/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:13:25 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/12 14:57:47 by jqueijo-         ###   ########.fr       */
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

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap Copy Constructor called. Copy: ";
	std::cout << other.name << " into: " << this->name << std::endl;
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
	if (this->hitPoints <= 0) {
		std::cout << this->name << ": \"Uh-oh! Me is dead?! ";
		std::cout << "How am I supposed to guard?\"" << std::endl;
		return ;
	}
	if (this->energyPoints == 0) {
		std::cout << this->name << ": \"Uh-oh! No energy?! ";
		std::cout << "I can't guard..\"" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ScavTrap: " << this->name << " in Gate Keeper mode! ";
	std::cout << "Nothing gets past me! Unless... wait, was I supposed to stop that guy?" << std::endl;
}
