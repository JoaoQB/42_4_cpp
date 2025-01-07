/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:22:00 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/07 15:21:12 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/Phonebook.hpp"
#include <iostream>

Contact::Contact() {
	std::cout << "Contact constructed" << std::endl;
	return;
}

Contact::~Contact() {
	std::cout << "Contact destroyed" << std::endl;
	return;
}
