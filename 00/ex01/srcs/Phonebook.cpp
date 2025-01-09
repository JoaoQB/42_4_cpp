/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:22:13 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/09 11:39:30 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/Phonebook.hpp"
#include <iostream>
#include <sstream>
#include <string>

int	Phonebook::isValidContact(std::string input) {
	std::stringstream	ss;
	int					index;

	ss << input;
	ss >> index;
	if (ss.fail() || !ss.eof()) {
		return (-1);
	}
	if (index < 1 || index > this->savedContacts) {
		return (-1);
	}
	return (index);
}

void	Phonebook::searchContact() {
	std::string	input;
	int			contact;

	if (savedContacts < 1) {
		std::cout << "No saved contacts" << std::endl;
		return ;
	}
	std::cout << "\n** Saved Contacs **\n" << std::endl;
	std::cout << "   Index  |First Name| Last Name| Nickname " << std::endl;
	for (int i = 0; i < savedContacts; i++) {
		this->contacts[i].displayContacts();
	}
	std::cout << "Please choose" << std::endl;
	std::cout << "Index: ";
	std::getline(std::cin, input);
	contact = isValidContact(input);
	if (contact == -1) {
		std::cout << "Index not valid" << std::endl;
		return;
	}
	this->contacts[contact - 1].displayFullContact();
	return;
}

void	Phonebook::addContact() {
	std::cout << "\n** New Contact **\n" << std::endl;
	this->contacts[currentIndex].setContact(currentIndex);
	currentIndex = (currentIndex + 1) % MAXCONTACTS;
	if (savedContacts < MAXCONTACTS) {
		savedContacts++;
	}
	return;
}

std::string	Phonebook::phonebookInit() {
	std::string	input;

	std::cout << "\nEnter an option (ADD, SEARCH, EXIT):\n" << std::endl;
	std::cout << "-> ";
	std::getline(std::cin, input);
	for (int i = 0; input[i]; i++) {
		input[i] = toupper(input[i]);
	}
	return (input);
}

Phonebook::Phonebook() {
	// std::cout << "Phonebook constructed" << std::endl;
	this->savedContacts = 0;
	this->currentIndex = 0;
	return;
}

Phonebook::~Phonebook() {
	// std::cout << "Phonebook destroyed" << std::endl;
	return;
}
