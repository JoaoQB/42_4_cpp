/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:05:14 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/07 11:30:46 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm()
	: signGradeRequirement(-1)
	, execGradeRequirement(-1) {
}

AForm::AForm(const std::string& name, const int signMinGrade, const int execMinGrade)
	: name(name)
	, isSigned(false)
	, signGradeRequirement(signMinGrade)
	, execGradeRequirement(execMinGrade) {
	if (signMinGrade < MAX_GRADE || execMinGrade < MAX_GRADE) {
		throw AForm::GradeTooHighException();
	}
	if (signMinGrade > MIN_GRADE || execMinGrade > MIN_GRADE) {
		throw AForm::GradeTooLowException();
	}
	std::cout << "Form Constructor: Created Form \"" << name
			<< "\" with sign grade requirement " << signMinGrade
			<< " and execute grade requirement " << execMinGrade << std::endl;
}

AForm::AForm(const AForm &other)
	: name(other.name)
	, isSigned(other.isSigned)
	, signGradeRequirement(other.signGradeRequirement)
	, execGradeRequirement(other.execGradeRequirement) {
	std::cout << "Form Copy Constructor: Copied Form \"" << name << "\"" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form Destructor: Destroying Form \"" << name << "\"" << std::endl;
}

AForm& AForm::operator=(const AForm &other) {
	std::cout << "Form = Assignment: Copying signed status from \""
			<< other.name << "\" to \"" << this->name << "\"" << std::endl;
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return (*this);
}

const std::string& AForm::getName() const {
	return (this->name);
}

bool AForm::getIsSigned() const {
	return (this->isSigned);
}

int AForm::getSignGradeRequirement() const {
	return (this->signGradeRequirement);
}

int AForm::getExecuteGradeRequirement() const {
	return (this->execGradeRequirement);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (this->isSigned == true) {
		throw AForm::FormAlreadySignedException();
	}
	else if (bureaucrat.getGrade() > this->signGradeRequirement) {
		throw AForm::GradeTooLowException();
	}
	this->isSigned = true;
}

void AForm::tryExecution(const Bureaucrat& bureaucrat) const {
	if (!this->isSigned) {
		throw AForm::FormNotSignedException();
	}
	else if (bureaucrat.getGrade() > this->execGradeRequirement) {
		throw AForm::GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const throw() {
	return("Form: Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return("Form: Grade is too low!");
}

const char* AForm::FormAlreadySignedException::what() const throw() {
	return("Form: is already signed!");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return("Form: Form is not signed, it can't be executed!");
}

std::ostream& operator<<(std::ostream &out, const AForm &form) {
	out << "Form \"" << form.getName() << "\", Signed: "
		<< (form.getIsSigned() ? "Yes" : "No")
		<< ", Sign Grade Requirement: " << form.getSignGradeRequirement()
		<< ", Execute Grade Requirement: " << form.getExecuteGradeRequirement();
	return (out);
}
