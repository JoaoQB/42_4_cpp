/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:59:27 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/18 14:57:34 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor: Initialized with empty ideas." << std::endl;
	for (int i = 0; i < 100; ++i) {
		this->ideas[i].clear();
		ideas[i] = "Empty idea";
	}
}

Brain::Brain(Brain const &other) {
	std::cout << "Brain Copy: Copied ideas from another brain." << std::endl;
	*this = other;
}

Brain &Brain::operator=(Brain const &other) {
	std::cout << "Brain =: Assigned ideas from another brain." << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Destructor: Cleaning up the brain." << std::endl;
}
