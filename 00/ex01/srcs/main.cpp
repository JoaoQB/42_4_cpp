/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:37:08 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/08 10:18:58 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/Phonebook.hpp"
#include <iostream>

int	main(void) {
	Phonebook	myPhonebook;
	std::string	input;
	while (true) {
		input = myPhonebook.phonebookInit();
		if (!input.compare("ADD")) {
			myPhonebook.addContact();
		} else if (!input.compare("SEARCH")) {
			myPhonebook.searchContact();
		} else if (!input.compare("EXIT")) {
			return (0);
		} else {
			std::cout << "Option not valid" << std::endl;
		}
	}

	return (0);
}
