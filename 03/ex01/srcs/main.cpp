/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:50:10 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/12 14:48:46 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main() {
	// Create a ClapTrap object
	ClapTrap claptrap("CLTP");
	claptrap.attack("target1");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	std::cout << std::endl; // Separate outputs for clarity

	// Create a ScavTrap object
	ScavTrap scavtrap("SCVT");
	scavtrap.attack("target2");
	scavtrap.takeDamage(20);
	scavtrap.beRepaired(10);
	scavtrap.guardGate();

	std::cout << std::endl; // Separate outputs for clarity

	// Create a ScavTrap from an existing one
	ScavTrap scavtrap2(scavtrap);
	scavtrap2.attack("target3");

	std::cout << std::endl; // Separate outputs for clarity

	// Assignment operator test
	ScavTrap scavtrap3("SCVT3");
	scavtrap3 = scavtrap;
	scavtrap3.attack("target4");

	std::cout << std::endl; // Separate outputs for clarity

	// Test ClapTrap with low energy and hit points
	ClapTrap lowEnergyTrap("LOW_ENERGY");
	lowEnergyTrap.takeDamage(10);  // Should trigger dramatic death
	lowEnergyTrap.beRepaired(5);    // Should indicate no energy for repair

	lowEnergyTrap = scavtrap2;
	lowEnergyTrap.takeDamage(100);

	return (0);
}
