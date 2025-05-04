/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:56:17 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/04 12:45:12 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# define N_CLASSES 3
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
		static const std::string classNames[N_CLASSES];
		int getForm (const std::string& name);

	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string name, const std::string target);

		class FormNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
