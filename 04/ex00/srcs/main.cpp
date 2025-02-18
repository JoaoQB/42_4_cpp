/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:19:03 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/18 13:12:54 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"


void testConstructors() {
	std::cout << "\n=== Constructor & Destructor Test ===\n";

	Animal* a = new Animal();
	Animal* d = new Dog();
	Animal* c = new Cat();
	Dog* d1 = new Dog();
	Dog* d2 = new Dog();
	const Dog dog = Dog();
	const Animal a2 = Dog(); // Should create differently than pointer

	delete a;
	delete d;
	delete c;
	delete d1;
	delete d2;
}

void testPolymorphism() {
	std::cout << "\n=== Polymorphism Test ===\n";

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void testCopyAssignment() {
	std::cout << "\n=== Copy & Assignment Test ===\n";

	Dog dog1;
	Dog dog2;
	dog2 = dog1; // Assignment test

	Cat cat1;
	Cat cat2(cat1); // Copy constructor test
}

void testWrongAnimals() {
	std::cout << "\n=== WrongAnimal & WrongCat Test ===\n";

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << "\nChecking Types:\n";
	std::cout << "WrongAnimal Type: " << wa->getType() << std::endl;
	std::cout << "WrongCat Type: " << wc->getType() << std::endl;

	std::cout << "\nChecking Sounds:\n";
	wa->makeSound();  // Should print generic wrong animal sound
	wc->makeSound();  // Should print wrong animal sound (not "Meow!")

	delete wa;
	delete wc;
}

void testEdgeCases() {
	std::cout << "\n=== Edge Cases Test ===\n";

	Dog* d1 = new Dog();
	Dog* d2 = new Dog(*d1); // Copy constructor test
	*d2 = *d1; // Self-assignment test

	delete d1;
	delete d2;
}

int main() {
	testConstructors();
	testPolymorphism();
	testCopyAssignment();
	testWrongAnimals();
	testEdgeCases();

	std::cout << "\n=== All Tests Completed ===\n";
	return 0;
}
