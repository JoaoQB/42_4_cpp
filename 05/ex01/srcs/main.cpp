/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:59:44 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/03/30 12:24:41 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;

		Form taxForm("TaxForm", 45, 30);
		std::cout << taxForm << std::endl;

		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;

		Bureaucrat alice("Alice", 40);
		std::cout << alice << std::endl;

		alice.signForm(taxForm);
		std::cout << taxForm << std::endl;
		alice.signForm(taxForm);

		Form invalidForm("InvalidForm", 0, 160);
		std::cout << invalidForm << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
