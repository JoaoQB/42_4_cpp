/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:59:27 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/19 14:14:59 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor: Initialized with empty ideas." << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "Empty idea";
	}
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain Copy: Copied ideas from another brain." << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = other.ideas[i];
	}
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

void Brain::set_idea(int index, const std::string &idea) {
	if (index < 0 || index >= ideasNumber) {
		std::cout << "Brain: Can't set an idea with that index." << std::endl;
		return ;
	}
	ideas[index] = idea;
}

std::string Brain::get_idea(int index) const {
	if (index < 0 || index >= ideasNumber) {
		return "";
	}
	return ideas[index];
}
