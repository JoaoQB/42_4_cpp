/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:36:44 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/13 14:57:31 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplacer.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Please run with three parameters: '<filename> <s1> <s2>'" << std::endl;
		return (1);
	}
	StringReplacer	replacer(argv[1], argv[2], argv[3]);
	replacer.replaceToFile();
	return (0);
}
