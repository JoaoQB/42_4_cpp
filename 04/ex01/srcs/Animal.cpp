/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:09:02 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/21 14:14:39 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : type("Polymorphic Animal") {
	std::cout << "Animal Constructor: God blessed us with a " << this->type;
	std::cout << "!" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal Copy: Let's create a " << this->type << " clone!" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor: It's time for " << this->type << " to return home";
	std::cout << "!" << std::endl;
}
Animal& Animal::operator=(const Animal &other) {
	std::cout << "Animal =: " << this->type << " = " << other.type << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const{
	std::cout << "Animal: No one knows what the " << this->type;
	std::cout << " sounds like!" << std::endl;
}
