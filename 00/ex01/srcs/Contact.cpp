/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:22:00 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/09 14:50:00 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
// #include "../includes/Phonebook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

void	Contact::displayFullContact() {
	std::cout << "First Name: ";
	std::cout << this->firstName << std::endl;
	std::cout << "Last Name: ";
	std::cout << this->lastName << std::endl;
	std::cout << "Nickname: ";
	std::cout << this->nickname << std::endl;
	std::cout << "Phone Number: ";
	std::cout << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: ";
	std::cout << this->darkestSecret << std::endl;
}

void	Contact::displayField(std::string field) {
	int width = 10;
	if (field.length() > 10) {
		std::cout << field.substr(0, width - 1) << ".";
	} else {
		std::cout << std::setw(width) << field;
	}
}

void	Contact::displayContacts() {
	std::stringstream	ss;

	ss << this->index;
	displayField(ss.str());
	std::cout << "|";
	displayField(this->firstName);
	std::cout << "|";
	displayField(this->lastName);
	std::cout << "|";
	displayField(this->nickname);
	std::cout << std::endl;
}

int	Contact::isValidPhoneNumber(std::string field) {
	for (int i = 0; field[i]; i++) {
		if (!isdigit(field[i])) {
			std::cout << "Please use only numeric characters" << std::endl;
			return (0);
		}
	}
	return (1);
}

int	Contact::isValidField(std::string field) {
	for (int i = 0; field[i]; i++) {
		if (!isalnum(field[i])) {
			std::cout << "Please use only alphanumeric characters" << std::endl;
			return (0);
		}
	}
	return (1);
}

std::string	Contact::getNumber(std::string field) {
	std::string	new_field;

	std::cout << "Please input:" << std::endl;
	std::cout << field << ": ";
	std::getline(std::cin, new_field);
	if (std::cin.eof()) {
		std::cout << std::endl;
		return (new_field);
	} else if (new_field.length() == 0 || !isValidPhoneNumber(new_field)) {
		return (Contact::getNumber(field));
	}
	return (new_field);
}

std::string	Contact::getField(std::string field) {
	std::string	new_field;

	std::cout << "Please input:" << std::endl;
	std::cout << field << ": ";
	std::getline(std::cin, new_field);
	if (std::cin.eof()) {
		std::cout << std::endl;
		return (new_field);
	} else if (new_field.length() == 0 || !isValidField(new_field)) {
		return (Contact::getField(field));
	}
	return (new_field);
}

void	Contact::setContact(int	index) {
	this->index = index + 1;
	this->firstName = getField("First Name");
	this->lastName = getField("Last Name");
	this->nickname = getField("Nickname");
	this->phoneNumber = getNumber("Phone Number");
	this->darkestSecret = getField("Darkest Secret");
}

Contact::~Contact() {
	// std::cout << "Contact destroyed" << std::endl;
	return;
}

Contact::Contact() {
	// std::cout << "Contact constructed" << std::endl;
	this->index = -1;
	return;
}
