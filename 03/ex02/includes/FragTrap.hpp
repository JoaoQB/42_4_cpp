/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:57:47 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/10 15:59:59 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : public ClapTrap {
	public:
		FragTrap(std::string const &name);
		FragTrap(const FragTrap &other);
		~FragTrap();
		FragTrap& operator=(const FragTrap &other);
		void highFivesGuys(void);
};

#endif
