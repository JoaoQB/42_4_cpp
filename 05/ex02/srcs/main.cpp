/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:59:44 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/04/22 18:06:55 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat boss("Alice", 1); // Grade 1 can do everything
		std::cout << boss << std::endl;

		std::cout << "\n=== ShrubberyCreationForm ===" << std::endl;
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		boss.signForm(shrub);
		boss.executeForm(shrub);

		std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;
		boss.signForm(robot);
		for (int i = 0; i < 4; ++i) {  // Multiple executions to test randomness
			boss.executeForm(robot);
		}

		std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
		PresidentialPardonForm pardon("Ford Prefect");
		std::cout << pardon << std::endl;
		boss.signForm(pardon);
		boss.executeForm(pardon);

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
