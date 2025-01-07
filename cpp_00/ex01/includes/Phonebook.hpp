/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:14:45 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/07 15:33:00 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class Phonebook {
	public:
		Phonebook();
		~Phonebook();
		std::string	phonebookInit();
		void		addContact();
		void		searchContact();
	private:
		Contact	contacts[8];
};

#endif
