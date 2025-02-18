/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:59:19 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/18 13:14:59 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << this->type << " Constructor: \"Miau Miau!\"" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat Copy: Let's create a " << this->type << " Dolly!" << std::endl;
}

Cat::~Cat() {
	std::cout << this->type << " Destructor: \"Miaaaau!\"" << std::endl;
}
Cat& Cat::operator=(const Cat &other) {
	std::cout << "Cat =: " << this->type << " = " << other.type << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << this->type << ": \"Miau Miau!\"" << std::endl;
}
