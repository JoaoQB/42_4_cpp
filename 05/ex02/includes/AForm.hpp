/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:50:31 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/04/22 18:04:40 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

# define MIN_GRADE	150
# define MAX_GRADE	1

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGradeRequirement;
		const int			execGradeRequirement;

		AForm();
	public:
		AForm(const std::string& name, const int signGradeRequirement, const int execGradeRequirement);
		AForm(const AForm &other);
		virtual ~AForm() = 0;

		AForm& operator=(const AForm &other);

		const std::string& getName() const;
		bool getIsSigned() const;
		int getSignGradeRequirement() const;
		int getExecuteGradeRequirement() const;

		void beSigned(const Bureaucrat& bureaucrat);
		void tryExecution(const Bureaucrat& bureaucrat) const;
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, const AForm &form);

#endif
