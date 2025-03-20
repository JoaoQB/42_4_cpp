/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:30:58 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/03/20 17:35:17 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void) {
	Bureaucrat *b1 = NULL;
	try {
		b1 = new Bureaucrat("John", 1);

		std::cout << *b1;

		Bureaucrat b2("Nancy", 1);
		std::cout << b2;

		Bureaucrat b3("Oliver", 150);
		std::cout << b3;

		try {
			Bureaucrat b4("Invalid", 151);
		} catch (const std::exception& e) {
			std::cout << "Expected exception: " << e.what() << std::endl;
		}
		try {
			b3.incrementGrade();
			std::cout << b3;
			b3.decrementGrade();
			std::cout << b3;
			// Cause exceptions
			b3.decrementGrade();
			// std::cout << b3;
			b2.incrementGrade();
			std::cout << b2;
		} catch (const std::exception& e) {
			std::cout << "Expected exception: " << e.what() << std::endl;
		}

	} catch (const std::exception& e) {
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	if (b1) {
		std::cout << *b1;
		Bureaucrat	b2(*b1);
		delete (b1);
		b1 = NULL;
	}

	return (0);
}
