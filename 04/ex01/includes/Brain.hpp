/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:54:41 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/02/19 14:00:45 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#define ideasNumber 100

#include <string>
#include <iostream>

class Brain {
	private:
		std::string ideas[ideasNumber];
	public:
		Brain();
		Brain(const Brain &other);
		virtual ~Brain();
		Brain& operator=(const Brain &other);
		void set_idea(int index, const std::string &idea);
		std::string	get_idea(int index) const;
};

#endif
