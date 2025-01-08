/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:02:11 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/07 11:53:44 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char **argv) {
	std::string	str;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	} else {
		for (int i = 1; i < argc; i++) {
			str = argv[i];
			for (int i = 0; str[i]; i++) {
				str[i] = std::toupper(str[i]);
			}
			std::cout << str;
		}
		std::cout << std::endl;
	}
}
