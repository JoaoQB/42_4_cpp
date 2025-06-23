/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:42:26 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/23 14:53:50 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 3) {
		std::cerr << "Error: invalid input, "
			<< "please provide at least two positive ints as arguments.\n"
			<< "Usage: './PmergeMe <positiveInteger> <positiveInteger> [...]'\n"
			<< "Example: './PmergeMe 5 9 1 20 3'" << std::endl;
		return 1;
	}
	try {
		PmergeMe sorter(argc, argv);
		sorter.sortAndLog();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
