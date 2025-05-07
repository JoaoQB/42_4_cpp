/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:59:44 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/07 11:23:41 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <unistd.h>

int main() {
	try {
		Bureaucrat boss("Alice", 1);
		std::cout << boss << std::endl;

		std::cout << "\n=== ShrubberyCreationForm ===" << std::endl;
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		boss.signForm(shrub);
		boss.signForm(shrub);
		boss.executeForm(shrub);

		std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;
		boss.signForm(robot);
		for (int i = 0; i < 10; ++i) {
			boss.executeForm(robot);
			usleep(900000);
		}

		std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
		PresidentialPardonForm pardon("Ford Prefect");
		std::cout << pardon << std::endl;
		boss.signForm(pardon);
		boss.executeForm(pardon);
		Bureaucrat graduate("Johny", 20);
		graduate.signForm(pardon);
		graduate.executeForm(pardon);

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
