/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:59:21 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/18 13:15:09 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << this->type << " Constructor: \"WOF WOF!\"" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog Copy: Let's create a " << this->type << " Dolly!" << std::endl;
}

Dog::~Dog() {
	std::cout << this->type << " Destructor: \"WOOOF!\"" << std::endl;
}
Dog& Dog::operator=(const Dog &other) {
	std::cout << "Dog =: " << this->type << " = " << other.type << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << this->type << ": \"WOF WOF!\"" << std::endl;
}
