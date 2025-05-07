/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:11:51 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/07 11:00:11 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5) {
	this->target = target;
	std::cout << "PresidentialPardonForm Constructor: Created with target \""
			<< target << "\"\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm("PresidentialPardonForm", 25, 5) {
	this->target = other.target;
	std::cout << "PresidentialPardonForm Copy Constructor: Copied with target \""
			<< target << "\"\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Destructor: Destroying form with target \""
			<< target << "\"\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << "PresidentialPardonForm = Assignment: Copying from \""
			<< other.getName() << "\" to \"" << this->getName() << "\"" << std::endl;
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	this->tryExecution(executor);
	std::cout << "PresidentialPardonForm Execution: \"" << target
			<< "\" has been pardoned by Zaphod Beeblebrox.\n";
}
