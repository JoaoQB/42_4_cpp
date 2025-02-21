/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:56:09 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/21 12:14:03 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
		Animal();
		Animal(const Animal &other);
	public:
		virtual ~Animal();
		Animal& operator=(const Animal &other);
		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif
