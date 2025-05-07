/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:50:31 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/07 11:08:17 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

# define MIN_GRADE	150
# define MAX_GRADE	1

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGradeRequirement;
		const int			execGradeRequirement;

		Form();
	public:
		Form(const std::string& name, const int signGradeRequirement, const int execGradeRequirement);
		Form(const Form &other);
		~Form();

		Form& operator=(const Form &other);

		const std::string& getName() const;
		bool getIsSigned() const;
		int getSignGradeRequirement() const;
		int getExecuteGradeRequirement() const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, const Form &form);

#endif
