/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:11:13 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/07 11:32:41 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137) {
	this->target = target;
	std::cout << "ShrubberyCreationForm Constructor: Created with target \""
			<< target << "\"\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm("ShrubberyCreationForm", 145, 137) {
	this->target = other.target;
	std::cout << "ShrubberyCreationForm Copy Constructor: Copied with target \""
			<< target << "\"\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm Destructor: Destroying form with target \""
			<< target << "\"\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "ShrubberyCreationForm = Assignment: Copying from \""
			<< other.getName() << "\" to \"" << this->getName() << "\"" << std::endl;
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	this->tryExecution(executor);
	std::string filename = this->target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile) {
		std::cerr << "ShrubberyCreationForm Error: Could not open file \""
				<< filename << "\" for writing.\n";
		return ;
	}
	outfile << "              v .   ._, |_  .,\n";
	outfile << "           `-._\\/  .  \\ /    |/_\n";
	outfile << "               \\\\  _\\, y | \\\\//\n";
	outfile << "         _\\_.___\\\\, \\\\/ -.\\||\n";
	outfile << "           `7-,--.`._||  / / ,\n";
	outfile << "           /'     `-. `./ / |/_.'\n";
	outfile << "                     |    |//\n";
	outfile << "                     |_    /\n";
	outfile << "                     |-   |\n";
	outfile << "                     |   =|\n";
	outfile << "                     |    |\n";
	outfile << "--------------------/ ,  . \\--------._\n";
	outfile.close();
}
