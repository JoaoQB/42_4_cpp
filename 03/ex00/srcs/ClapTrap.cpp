/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:57:51 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/10 13:48:56 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name) : name(name),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0) {
	std::cout << "ClapTrap Constructor called with name: ";
	std::cout << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap Copy Constructor called for: ";
	std::cout << other.name << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called for: ";
	std::cout << this->name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap Equal Assignment Operator Called" << std::endl;
	std::cout << this->name << " = " << other.name << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->energyPoints == 0) {
		std::cout << this->name << ": \"Uh-oh! No juice left!";
		std::cout << " How am I supposed to be an unstoppable killing machine?!\"";
		std::cout << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << this->name << ": \"Take THAT, " << target << "!\" *pew pew* ";
	std::cout << "(Dealt " << this->attackDamage << " damage!)\n";
	std::cout << "Energy remaining: " << this->energyPoints;
	std::cout << ". Not looking great, but hey, I'm still awesome!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->hitPoints -= amount;
	if (this->hitPoints <= 0) {
		std::cout << this->name << ": \"Oof! That hurt! System failure ";
		std::cout << "imminent! Tell my motherboard... I love her...";
		std::cout << " *dies dramatically*\"" << std::endl;
	} else {
		std::cout << this->name << ": \"Ow! That was totally unnecessary!";
		std::cout << " I have " << this->hitPoints << " HP left! Rude!\"";
		std::cout << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints == 0) {
		std::cout << this->name << ": \"I'm out of energy! No duct tape, ";
		std::cout << "no hope! Someone, please, send help!\"" << std::endl;
		return ;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << this->name << ": \"Self-repair engaged! ";
	std::cout << "Behold my incredible fixing skills!\"" << std::endl;
	std::cout << "Recovered " << amount;
	std::cout << " HP! Current HP: " << this->hitPoints;
	std::cout << ", Energy left: " << this->energyPoints;
	std::cout << ". I AM INVINCIBLE! ... Right?\"" << std::endl;
}
