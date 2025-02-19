/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:59:21 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/19 14:50:38 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << this->type << " Constructor: \"WOF WOF!\"" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog Copy: Let's create a " << this->type << " Dolly!" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Dog::~Dog() {
	std::cout << this->type << " Destructor: \"WOOOF!\"" << std::endl;
	delete this->brain;
}
Dog& Dog::operator=(const Dog &other) {
	std::cout << "Dog =: " << this->type << " = " << other.type << std::endl;
	if (this != &other) {
		this->type = other.type;
		delete brain;
		brain = new Brain(*(other.brain));
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << this->type << ": \"WOF WOF!\"" << std::endl;
}

Brain& Dog::getBrain() {
	return (*this->brain);
}
