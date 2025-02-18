/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:59:24 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/18 13:15:30 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "Wrong Cat";
	std::cout << this->type << " Constructor: \"MIAU????\"" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WCat Copy: Let's create a " << this->type << " Monster!" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << this->type << " Destructor: \"WOFMIAU?????\"" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat &other) {
	std::cout << "WCat =: " << this->type << " = " << other.type << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << this->type << ": \"Miau Miau??????\"" << std::endl;
}
