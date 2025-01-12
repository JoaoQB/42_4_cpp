/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:25:42 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/12 18:21:06 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) {
	this->type = type;
	std::cout << this->type << " activated" << std::endl;
}

Weapon::~Weapon() {
	std::cout << this->type << " destroyed" << std::endl;
}

// Returns a const reference to type
const std::string	&Weapon::getType() const {
	return (this->type);
}

// Sets type_ using the new one passed as parameter.
void	Weapon::setType(std::string newType) {
	this->type = newType;
}
