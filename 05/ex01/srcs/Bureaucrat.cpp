/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:15:10 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/03/30 12:26:01 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name(name)
	, grade(grade) {
	if (grade < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "Bureaucrat: " << this->name << " created with grade: "
			<< this->grade << "!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name)
	, grade(other.grade) {
	std::cout << "Bureaucrat: Copy of " << other.name << " created with grade "
			<< other.grade << "! (Copy Constructor)" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: " << this->name << " with grade " << this->grade
			<< " destroyed! (Destructor)" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return (*this);
}

const std::string& Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

void Bureaucrat::incrementGrade() {
	if (this->grade - 1 < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade + 1 > MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade++;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signs " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << this->name << " cannot sign " << form.getName()
				<< " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return("Grade is too low!");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade()
		<< ".";
	return (out);
}
