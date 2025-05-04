/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:59:44 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/04 13:01:24 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main() {
	try {
		Bureaucrat boss("Alice", 1);
		Bureaucrat internBureaucrat("Bob", 150);
		Intern intern;

		std::cout << "\n=== Intern Creates Forms ===\n";
		AForm* shrubbery = intern.makeForm("shrubbery creation", "Garden");
		AForm* robotomy = intern.makeForm("robotomy request", "Bender");
		AForm* pardon = intern.makeForm("presidential pardon", "Ford Prefect");

		std::cout << "\n=== Boss Signs & Executes ===\n";
		shrubbery->beSigned(boss);
		shrubbery->execute(boss);

		robotomy->beSigned(boss);
		robotomy->execute(boss);

		pardon->beSigned(boss);
		pardon->execute(boss);

		std::cout << "\n=== Low-Rank Bureaucrat Tries ===\n";
		try {
			shrubbery->beSigned(internBureaucrat);
		} catch (const std::exception& e) {
			std::cerr << "Signing failed: " << e.what() << std::endl;
		}

		try {
			shrubbery->execute(internBureaucrat);
		} catch (const std::exception& e) {
			std::cerr << "Execution failed: " << e.what() << std::endl;
		}

		std::cout << "\n=== Intern Tries Unknown Form ===\n";
		try {
			AForm* unknown = intern.makeForm("death ray", "Earth");
			delete unknown;
		} catch (const std::exception& e) {
			std::cerr << "Unknown form error: " << e.what() << std::endl;
		}

		delete shrubbery;
		delete robotomy;
		delete pardon;

	} catch (const std::exception& e) {
		std::cerr << "Fatal error: " << e.what() << std::endl;
	}
	return 0;
}
