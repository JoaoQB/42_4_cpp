/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:53:25 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/22 15:08:18 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <iostream>

void ft_error(std::string errorMessage) {
	std::cerr << errorMessage << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		return (ft_error("Please input: './btc <transactions_filepath>'"), 1);
	}

	try {
		std::string requestFilePath = argv[1];
		BitcoinExchange btcCalculator(requestFilePath);

		btcCalculator.calculatePrices();
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
