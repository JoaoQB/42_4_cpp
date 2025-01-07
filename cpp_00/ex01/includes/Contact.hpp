/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:15:17 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/07 15:33:39 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	public:
		Contact();
		~Contact();
	private:
		std::string	name;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		int			phoneNumber;
		std::string	darkestSecret;
};

#endif
