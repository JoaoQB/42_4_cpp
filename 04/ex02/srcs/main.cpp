/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:19:03 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/19 15:29:20 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

void testAnimalArray() {
	std::cout << "\n=== Animal Array Test ===\n";
	const int numAnimals = 6;
	Animal *animals[numAnimals];

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
	// Animal* animal3 = new Animal(); // Uncomment to check protected constructor
	// Animal* animal4 = new Animal(*(animal2)); // Uncomment to check protected copy constructor

	// Animal dog = Dog();
	Dog dog2 = Dog();
	dog2.makeSound();

	animal1->makeSound();
	animal2->makeSound();
	dog2.makeSound();

	delete animal1;
	delete animal2;
}

void testDeepCopy() {
	std::cout << "\n=== Deep Copy Test ===\n";

	Dog originalDog;
	originalDog.getBrain().set_idea(0, "Fetch the ball");

	Dog copiedDog = Dog(originalDog);
	Dog copiedDog2 = originalDog;
	Dog assignedDog;
	assignedDog = originalDog;

	// Check that ideas are independent
	std::cout << "Original Dog idea: " << originalDog.getBrain().get_idea(0) << std::endl;
	std::cout << "Copied Dog idea: " << copiedDog.getBrain().get_idea(0) << std::endl;
	std::cout << "Copied Dog 2 idea: " << copiedDog2.getBrain().get_idea(0) << std::endl;
	std::cout << "Assigned Dog idea: " << assignedDog.getBrain().get_idea(0) << std::endl;

	// Modify the copied dog's brain
	copiedDog.getBrain().set_idea(0, "New Idea");

	// Verify that the original dog is unaffected
	std::cout << "After modifying copied Dog idea:\n";
	std::cout << "Original Dog idea: " << originalDog.getBrain().get_idea(0) << std::endl; // Should be "Fetch the ball"
	std::cout << "Copied Dog idea: " << copiedDog.getBrain().get_idea(0) << std::endl; // Should be "New Idea"
	std::cout << "Copied Dog 2 idea: " << copiedDog2.getBrain().get_idea(0) << std::endl;
	std::cout << "Assigned Dog idea: " << assignedDog.getBrain().get_idea(0) << std::endl;
}

// Test function for edge cases
void testWrongIdeas() {
	std::cout << "\n=== Edge Cases Test ===\n";

	Dog dog;
	dog.getBrain().set_idea(0, "Bark");
	dog.getBrain().set_idea(1, "");
	std::cout << dog.getBrain().get_idea(0) << std::endl;
	std::cout << dog.getBrain().get_idea(1) << std::endl;
	// Check out of bounds for setting idea
	dog.getBrain().set_idea(100, "Out of bounds"); // Should print error message
	dog.getBrain().set_idea(-1, "Negative index"); // Should print error message

	// Check out of bounds for getting idea
	std::cout << "Trying to get an idea with out of bounds index: "
			<< dog.getBrain().get_idea(100) << std::endl; // Should return empty string
}

void testTemporaryDogObject() {
	std::cout << "\n=== Temporary Dog Object Test ===\n";

	Dog *outsideDog = new Dog();

	{
		Dog tempDog;
		tempDog.getBrain().set_idea(0, "Bark loudly");
		tempDog.getBrain().set_idea(1, "Chase the cat");

		// Print ideas from the temporary dog
		std::cout << "Temporary Dog ideas:\n";
		std::cout << "Idea 0: " << tempDog.getBrain().get_idea(0) << std::endl; // Should print "Bark loudly"
		std::cout << "Idea 1: " << tempDog.getBrain().get_idea(1) << std::endl; // Should print "Chase the cat"

		*outsideDog = tempDog;
	} // tempDog goes out of scope here

	std::cout << "Outside Dog ideas after temporary Dog goes out of scope:\n";
	std::cout << "Outside Dog idea 0: " << outsideDog->getBrain().get_idea(0) << std::endl; // Should print "Bark loudly"
	std::cout << "Outside Dog idea 1: " << outsideDog->getBrain().get_idea(1) << std::endl; // Should print "Chase the cat"

	delete outsideDog;
}

int main() {
	testAnimalArray();
	testPolymorphism();
	testDeepCopy();
	testWrongIdeas();
	testTemporaryDogObject(); // Call the new test function

	return 0;
}
