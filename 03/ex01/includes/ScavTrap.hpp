/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:13:22 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/02 20:12:04 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

// Inherit constructors and destructor from Clap Trap
// However its own constructors, destructors and attack will print different messages.
// Proper construction/destruction chaining.
// 		build claptrap then scavtrap, destroy opposite
// ScavTrap uses the attributes of ClapTrap (update claptrap in consequence)
// Initialize them to:
// Name
// Hit Points 100
// Energy Points 50
// Attack Damage 20
// Its own special capacity, void guardGate();
// 		displays message informing scaptrap is now in Gate keeper mode.

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string const &name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &other);
		void attack(const std::string& target);
		void guardGate();
};

#endif
