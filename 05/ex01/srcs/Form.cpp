/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:05:14 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/03/30 12:23:17 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form()
	: signGradeRequirement(-1)
	, execGradeRequirement(-1) {
}

Form::Form(const std::string& name, const int signMinGrade, const int execMinGrade)
	: name(name)
	, isSigned(false)
	, signGradeRequirement(signMinGrade)
	, execGradeRequirement(execMinGrade) {
	if (signMinGrade < MAX_GRADE || execMinGrade < MAX_GRADE) {
		throw Form::GradeTooHighException();
	}
	if (signMinGrade > MIN_GRADE || execMinGrade > MIN_GRADE) {
		throw Form::GradeTooLowException();
	}
	std::cout << "Form Constructor: Created form \"" << name
			<< "\" with sign grade requirement " << signMinGrade
			<< " and execute grade requirement " << execMinGrade << std::endl;
}

Form::Form(const Form &other)
	: name(other.name)
	, isSigned(other.isSigned)
	, signGradeRequirement(other.signGradeRequirement)
	, execGradeRequirement(other.execGradeRequirement) {
	std::cout << "Form Copy Constructor: Copied form \"" << name << "\"" << std::endl;
}

Form::~Form() {
	std::cout << "Form Destructor: Destroying form \"" << name << "\"" << std::endl;
}

Form& Form::operator=(const Form &other) {
	std::cout << "Form = Assignment: Copying signed status from \""
			<< other.name << "\" to \"" << this->name << "\"" << std::endl;
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return (*this);
}

const std::string& Form::getName() const {
	return (this->name);
}

bool Form::getIsSigned() const {
	return (this->isSigned);
}

int Form::getSignGradeRequirement() const {
	return (this->signGradeRequirement);
}

int Form::getExecuteGradeRequirement() const {
	return (this->execGradeRequirement);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (this->isSigned == true) {
		std::cerr <<  "Form already signed" << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > this->signGradeRequirement) {
		throw Form::GradeTooLowException();
	}
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return("Form: Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return("Form: Grade is too low!");
}

std::ostream& operator<<(std::ostream &out, const Form &form) {
	out << "Form \"" << form.getName() << "\", Signed: "
		<< (form.getIsSigned() ? "Yes" : "No")
		<< ", Sign Grade Requirement: " << form.getSignGradeRequirement()
		<< ", Execute Grade Requirement: " << form.getExecuteGradeRequirement();
	return (out);
}
