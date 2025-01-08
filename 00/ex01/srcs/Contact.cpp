/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:22:00 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/08 13:42:52 by jqueijo-         ###   ########.fr       */
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

std::string	Contact::getField(std::string field) {
	std::string	new_field;

	std::cout << "Please input:" << std::endl;
	std::cout << field << ": ";
	std::getline(std::cin, new_field);
	if (new_field.length() == 0) {
		return (Contact::getField(field));
	}
	return (new_field);
}

void	Contact::setContact(int	index) {
	this->index = index + 1;
	this->firstName = getField("First Name");
	this->lastName = getField("Last Name");
	this->nickname = getField("Nickname");
	this->phoneNumber = getField("Phone Number");
	this->darkestSecret = getField("Darkest Secret");
}

Contact::~Contact() {
	std::cout << "Contact destroyed" << std::endl;
	return;
}

Contact::Contact() {
	std::cout << "Contact constructed" << std::endl;
	this->index = -1;
	return;
}
