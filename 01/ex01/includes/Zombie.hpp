/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:22:54 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/11 11:38:45 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		void	zombieInit(std::string name);
		void	announce(void);
};

Zombie	*zombieHorde(int N, std::string name);
void	announceAll(int N, Zombie *horde);

#endif
