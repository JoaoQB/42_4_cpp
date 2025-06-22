/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:34:10 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/22 16:52:50 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: please input './RPN <stringToCalculate>'" << std::endl;
		return 1;
	}
	const std::string& inputString = argv[1];
	try {
		RPN calculator(inputString);
		calculator.processExpression();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what()
			<< " '" << inputString << "'." << std::endl;
		return 1;
	}
	return 0;
}
