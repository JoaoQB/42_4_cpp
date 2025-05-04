/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:35:28 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/04 12:58:34 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

const std::string Intern::classNames[N_CLASSES] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::Intern() {
	std::cout << "Intern Constructor: Default intern created\n";
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern Copy Constructor: Copied intern\n";
	(void)other;
}

Intern::~Intern() {
	std::cout << "Intern Destructor: Intern destroyed\n";
}

Intern& Intern::operator=(Intern const &src) {
	std::cout << "Intern Assignment Operator: Assigned intern\n";
	(void)src;
	return *this;
}

int Intern::getForm(const std::string& name) {
	for (int i=0; i < N_CLASSES; ++i) {
		if (name == classNames[i]) {
			return (i + 1);
		}
	}
	return (-1);
}

AForm* Intern::makeForm(const std::string name, const std::string target) {
	int i = getForm(name);

	switch (i) {
		case 1:
			return new ShrubberyCreationForm(target);
		case 2:
			return new RobotomyRequestForm(target);
		case 3:
			return new PresidentialPardonForm(target);
		default:
			throw Intern::FormNotFoundException();
	}
}

const char* Intern::FormNotFoundException::what() const throw() {
	return("Intern: Intern Error: Requested form not found!");
}
