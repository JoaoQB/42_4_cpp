/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:12:40 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/15 12:19:59 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename IterT, typename T>
IterT easyfind(T& container, const int target) {
	IterT it = std::find(container.begin(), container.end(), target);

	if (it == container.end()) {
		throw std::out_of_range("Target not found");
	}
	return it;
}

#endif
