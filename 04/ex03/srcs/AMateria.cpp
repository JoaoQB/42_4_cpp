/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:46:35 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/08/08 13:32:01 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

AMateria::AMateria() : type("abstract") {
	std::cout << "AMateria Protected Constructor called\n";
}

AMateria::AMateria(std::string const& type) : type(type) {
	std::cout << "AMateria Constructor called, with type: " << this->type << ".\n";
}

AMateria::AMateria(const AMateria& src) : type (src.type) {
	std::cout << "AMateria Copy Constructor called, from type: " << src.type << ".\n";
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called, for type: " << this->type << ".\n";
}

AMateria& AMateria::operator=(const AMateria& other) {
	std::cout << this->type << "= " << other.type << "\n";
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

std::string const& AMateria:: getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << this->type << " AMateria does nothing to target: " << target.getName() << ".\n";
}


