/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:14:45 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/08 13:35:07 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAXCONTACTS 8
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
		Contact	contacts[MAXCONTACTS];
		int		currentIndex;
		int		savedContacts;

		int	isValidContact(std::string input);
};

#endif
