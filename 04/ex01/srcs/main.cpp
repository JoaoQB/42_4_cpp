/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:19:03 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/18 14:56:13 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

void testAnimalArray() {
	std::cout << "\n=== Animal Array Test ===\n";
	const int numAnimals = 6;
	Animal* animals[numAnimals];

	// Fill the array with Dogs and Cats
	for (int i = 0; i < numAnimals / 2; ++i) {
		animals[i] = new Dog();
	}
	for (int i = numAnimals / 2; i < numAnimals; ++i) {
		animals[i] = new Cat();
	}

	// Loop through the array and make sounds
	for (int i = 0; i < numAnimals; ++i) {
		animals[i]->makeSound();
	}

	// Delete all animals
	for (int i = 0; i < numAnimals; ++i) {
		delete animals[i];
	}
}

void testPolymorphism() {
	std::cout << "\n=== Polymorphism Test ===\n";

	Animal* animal1 = new Dog();
	Animal* animal2 = new Cat();

	animal1->makeSound();
	animal2->makeSound();

	delete animal1;
	delete animal2;
}

int main() {
	testAnimalArray();
	testPolymorphism();

	return 0;
}
