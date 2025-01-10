/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:02:22 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/01/10 13:45:55 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void) {
	Zombie	*stinger;

	stinger = Utils::newZombie("Stinger");
	delete (stinger);
	stinger = Utils::newZombie("Stinger");
	stinger->announce();
	delete (stinger);
	Utils::randomChump("Shuffler");
}
