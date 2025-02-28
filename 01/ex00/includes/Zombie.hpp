/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:04:21 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/10 13:43:39 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};

namespace Utils {
	// create a zombie, name it and return it to use outside function scope
	Zombie*	newZombie(std::string name);
	// Create a zombie, name it and the zombie announces itself.
	void	randomChump(std::string name);
};

#endif
