/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:25:17 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/11 11:40:55 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	// std::cout << "Zombie constructed"  << std::endl;
}

Zombie::~Zombie() {
	// std::cout << "Zombie destroyed"  << std::endl;
}

void	Zombie::zombieInit(std::string name) {
	this->name = name;
	// std::cout << "Zombie is called: " << this->name << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
