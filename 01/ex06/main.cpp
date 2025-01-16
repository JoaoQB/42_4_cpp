/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:44:39 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/16 14:22:44 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Please run: ./harlFilter <level>" << std::endl;
		std::cerr << "Levels available:\nDEBUG\nINFO\nWARNING\nERROR" << std::endl;
		return (1);
	}
	Harl	harley;
	harley.complain(argv[1]);
}
