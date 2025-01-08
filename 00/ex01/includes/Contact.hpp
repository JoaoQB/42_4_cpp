/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:15:17 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/08 13:36:24 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	public:
		Contact();
		~Contact();
		void	setContact(int index);
		void	displayContacts();
		void	displayFullContact();

	private:
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

		std::string	getField(std::string field);
		void		displayField(std::string field);
};

#endif
