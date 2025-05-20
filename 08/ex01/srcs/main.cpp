/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:33:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/20 12:02:05 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>

int main() {
	try {
		const unsigned int totalNumbers = 15000;
		Span sp(totalNumbers);

		std::cout << "Filling Span with 15,000 random numbers using addRandomNumbers()...\n";
		sp.addRandomNumbers(totalNumbers);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		std::cout << "\nFilling new Span using addRange from std::vector...\n";
		std::vector<int> numbers;
		numbers.reserve(totalNumbers);
		srand(time(0));
		for (unsigned int i = 0; i < totalNumbers; ++i) {
			numbers.push_back(rand());
		}

		Span sp2(totalNumbers);
		sp2.addRange<std::vector<int> >(numbers.begin(), numbers.end());

		std::cout << "Shortest Span (range): " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span (range): " << sp2.longestSpan() << std::endl;

		std::cout << "\nFilling Span using std::list...\n";
		std::list<int> lst;
		for (unsigned int i = 0; i < totalNumbers; ++i) {
			lst.push_back(rand());
		}

		Span sp3(totalNumbers);
		sp3.addRange<std::list<int> >(lst.begin(), lst.end());
		std::cout << "Shortest Span (list): " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest Span (list): " << sp3.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}

// int main() {
// 	try {
// 		// Create a Span with a maximum of 5 elements
// 		Span sp1(5);
// 		std::cout << "Contents of sp1 before filling:\n";
// 		sp1.printVector();

// 		// Will throw because there aren't enough elements
// 		std::cout << "Attempting span calculations on empty Span:\n";
// 		std::cout << "Shortest span: " << sp1.shortestSpan()
// 					<< ", Longest span: " << sp1.longestSpan() << std::endl;

// 	} catch (const std::exception& e) {
// 		std::cerr << "Exception: " << e.what() << "\n" << std::endl;
// 	}

// 	try {
// 		Span sp1(5);

// 		// Add numbers to sp1
// 		sp1.addNumber(-10);
// 		sp1.addNumber(-20);
// 		sp1.addNumber(30);

// 		std::cout << "Contents of sp1:\n";
// 		sp1.printVector();
// 		std::cout << "sp1: Shortest span: " << sp1.shortestSpan()
// 					<< ", Longest span: " << sp1.longestSpan() << std::endl;

// 		// Copy constructor
// 		Span sp2(sp1);
// 		std::cout << "\nContents of sp2 (copy of sp1):\n";
// 		sp2.printVector();

// 		// Assignment operator
// 		Span sp3(1);
// 		sp3 = sp1;
// 		std::cout << "\nContents of sp3 (assigned from sp1):\n";
// 		sp3.printVector();

// 		std::cout << "\nSpan objects created and copied successfully.\n" << std::endl;

// 		// Add more numbers to sp1
// 		sp1.addNumber(-4);
// 		sp1.addNumber(500);
// 		std::cout << "sp1 after filling up:\n";
// 		sp1.printVector();
// 		std::cout << "sp2:\n";
// 		sp2.printVector();
// 		std::cout << "sp3:\n";
// 		sp3.printVector();
// 		std::cout << "sp1: Shortest span: " << sp1.shortestSpan()
// 					<< ", Longest span: " << sp1.longestSpan() << std::endl;

// 		// Try to add beyond capacity — should throw
// 		sp1.addNumber(60); // Exception expected here

// 	} catch (const std::exception& e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

// 	return 0;
// }

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

