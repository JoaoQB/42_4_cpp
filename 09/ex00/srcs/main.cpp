/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:53:25 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/20 21:09:32 by jqueijo-         ###   ########.fr       */
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
		BitcoinExchange btcCalculator(requestFilePath); //TODO

		btcCalculator.calculatePrices(); //TODO
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
