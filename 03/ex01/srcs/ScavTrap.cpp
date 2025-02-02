/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:13:25 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/02 20:18:25 by jqueijo-         ###   ########.fr       */
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
	std::cout << "ClapTrap Copy Constructor called for: ";
	std::cout << other.name << std::endl;
	*this = other;
}
