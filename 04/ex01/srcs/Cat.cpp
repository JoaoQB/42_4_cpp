/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:59:19 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/19 14:50:47 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << this->type << " Constructor: \"Miau Miau!\"" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat Copy: Let's create a " << this->type << " Dolly!" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Cat::~Cat() {
	std::cout << this->type << " Destructor: \"Miaaaau!\"" << std::endl;
	delete this->brain;
}
Cat& Cat::operator=(const Cat &other) {
	std::cout << "Cat =: " << this->type << " = " << other.type << std::endl;
	if (this != &other) {
		this->type = other.type;
		delete brain;
		brain = new Brain(*(other.brain));
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << this->type << ": \"Miau Miau!\"" << std::endl;
}

Brain& Cat::getBrain() {
	return (*this->brain);
}
