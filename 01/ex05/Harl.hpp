/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:45:07 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/14 20:28:05 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#define N_FUNC 4
#include <string>
#include <iostream>

class Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		typedef	void (Harl::*funcPtr)();
		funcPtr		funcArray[N_FUNC];
		std::string	funcNames[N_FUNC];
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif
