/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:33:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/15 15:26:50 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>

int main() {
	try {
		// Create a Span with a maximum of 5 elements
		Span sp1(5);
		std::cout << "Contents of sp1 before filling:\n";
		sp1.printVector();

		// Will throw because there aren't enough elements
		std::cout << "Attempting span calculations on empty Span:\n";
		std::cout << "Shortest span: " << sp1.shortestSpan()
					<< ", Longest span: " << sp1.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n" << std::endl;
	}

	try {
		Span sp1(5);

		// Add numbers to sp1
		sp1.addNumber(-10);
		sp1.addNumber(-20);
		sp1.addNumber(30);

		std::cout << "Contents of sp1:\n";
		sp1.printVector();
		std::cout << "sp1: Shortest span: " << sp1.shortestSpan()
					<< ", Longest span: " << sp1.longestSpan() << std::endl;

		// Copy constructor
		Span sp2(sp1);
		std::cout << "\nContents of sp2 (copy of sp1):\n";
		sp2.printVector();

		// Assignment operator
		Span sp3(1);
		sp3 = sp1;
		std::cout << "\nContents of sp3 (assigned from sp1):\n";
		sp3.printVector();

		std::cout << "\nSpan objects created and copied successfully.\n" << std::endl;

		// Add more numbers to sp1
		sp1.addNumber(-4);
		sp1.addNumber(500);
		std::cout << "sp1 after filling up:\n";
		sp1.printVector();
		std::cout << "sp2:\n";
		sp2.printVector();
		std::cout << "sp3:\n";
		sp3.printVector();
		std::cout << "sp1: Shortest span: " << sp1.shortestSpan()
					<< ", Longest span: " << sp1.longestSpan() << std::endl;

		// Try to add beyond capacity — should throw
		sp1.addNumber(60); // Exception expected here

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
