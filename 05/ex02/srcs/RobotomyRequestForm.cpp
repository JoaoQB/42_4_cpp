/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:11:29 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/04/22 18:14:28 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

// Required grades: sign 72, exec 45
// Makes some drilling noises, then informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, it informs that the robotomy failed.

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45) {
	this->target = target;
	std::cout << "RobotomyRequestForm Constructor: Created with target \""
			<< target << "\"\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm("RobotomyRequestForm", 72, 45) {
	this->target = other.target;
	std::cout << "RobotomyRequestForm Copy Constructor: Copied with target \""
			<< target << "\"\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Destructor: Destroying form with target \""
			<< target << "\"\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "RobotomyRequestForm = Assignment: Copying from target \""
			<< other.target << "\" to \"" << this->target << "\"\n";
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	this->tryExecution(executor);
	std::cout << "RobotomyRequestForm Execution: Starting robotomy process on \""
			<< target << "\"\n";
	std::cout << "* LOUD DRILLING NOISES *\n";
	srand(time(0));
	if (rand() % 2) {
		std::cout << "RobotomyRequestForm Execution: \"" << target << "\" has been successfully robotomized!\n";
	} else {
		std::cout << "RobotomyRequestForm Execution: Robotomy failed on \"" << target << "\"\n";
	}
}
