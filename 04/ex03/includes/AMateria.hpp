/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:23:02 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/08/08 17:27:01 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria {
	protected:
		std::string type;
		AMateria();
		AMateria& operator=(const AMateria& other);

	public:
		AMateria(std::string const& type); // Subject
		AMateria(const AMateria& src);
		virtual ~AMateria();

		std::string const& getType() const; // Subject
		virtual AMateria* clone() const = 0; // Subject
		virtual void use(ICharacter& target); // Subject
};

#endif
