/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:26:11 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/18 13:15:25 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Pholyrphomic Wrong Animal") {
	std::cout << "WrongAnimal Constructor: What is this, a poor " << this->type;
	std::cout << "?" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << "WAnimal Copy: Oh God! A " << this->type << " clone!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WAnimal Destructor: Bless " << this->type << "!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WAnimal =: " << this->type << " = " << other.type << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong Animal: No one knows what the " << this->type;
	std::cout << " sounds like! I hope.." << std::endl;
}
