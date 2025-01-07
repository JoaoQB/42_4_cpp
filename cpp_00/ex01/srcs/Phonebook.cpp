/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:22:13 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/07 15:55:48 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/Phonebook.hpp"
#include <iostream>
#include <string>

Phonebook::Phonebook() {
	std::cout << "Phonebook constructed" << std::endl;
	return;
}

Phonebook::~Phonebook() {
	std::cout << "Phonebook destroyed" << std::endl;
	return;
}

std::string	Phonebook::phonebookInit() {
	std::string	input;

	std::cout << "Enter an option (ADD, SEARCH, EXIT):" << std::endl;
	std::getline(std::cin, input);
	for (int i = 0; input[i]; i++) {
		input[i] = toupper(input[i]);
	}
	return (input);
}

void	Phonebook::addContact() {
	std::cout << "Please add contact\n";
	return;
}

void	Phonebook::searchContact() {
	std::cout << "Please search contact\n";
	return;
}
