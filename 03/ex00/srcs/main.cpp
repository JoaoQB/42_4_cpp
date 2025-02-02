/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:50:10 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/01 19:59:39 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void) {
	std::cout << "\n--- Creating ClapTraps ---\n";
	ClapTrap clap1("CL4P-TP");
	ClapTrap clap2("FR4G-TP");

	std::cout << "\n--- Testing Copy Constructor ---\n";
	ClapTrap clap3(clap1); // Copy constructor

	std::cout << "\n--- Testing Assignment Operator ---\n";
	ClapTrap clap4("TEMP-TP");
	clap4 = clap2; // Assignment operator

	std::cout << "\n--- Battle Begins! ---\n";

	clap1.attack("FR4G-TP");
	clap2.takeDamage(5);

	clap2.attack("CL4P-TP");
	clap1.takeDamage(3);

	clap1.beRepaired(4);
	clap2.beRepaired(2);

	clap1.attack("FR4G-TP");
	clap2.takeDamage(5);

	clap2.attack("CL4P-TP");
	clap1.takeDamage(6);
	clap3.takeDamage(20);

	std::cout << "\n--- Running out of energy! ---\n";

	for (int i = 0; i < 10; i++) {
		clap1.attack("wall");
	}

	clap1.beRepaired(3);
	clap1.attack("FR4G-TP");

	std::cout << "\n--- End of Simulation ---\n";

	return 0;
}
