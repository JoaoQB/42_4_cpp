/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:50:10 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/12 14:59:42 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main() {
	std::cout << "=== Creating ClapTrap ===" << std::endl;
	ClapTrap clap("CLAPPY");

	std::cout << "\n=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("SCAVVY");
	ScavTrap scav2(scav);
	ScavTrap scav3("lol");
	scav3 = scav2;

	std::cout << "\n=== Creating FragTrap ===" << std::endl;
	FragTrap frag("FRAGGY");
	FragTrap frag2(frag);
	FragTrap frag3("lol");
	frag3 = frag2;

	std::cout << "\n=== ClapTrap Actions ===" << std::endl;
	clap.attack("bandit");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n=== ScavTrap Actions ===" << std::endl;
	scav.attack("psycho");
	scav.guardGate();
	scav.takeDamage(40);
	scav.beRepaired(20);

	std::cout << "\n=== FragTrap Actions ===" << std::endl;
	frag.attack("skag");
	frag.highFivesGuys();
	frag.takeDamage(50);
	frag.beRepaired(25);

	std::cout << "\n=== Destruction Begins ===" << std::endl;

	return 0;
}
