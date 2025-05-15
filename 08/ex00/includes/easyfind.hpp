/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:12:40 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/13 09:28:10 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T, typename IterT>
IterT easyfind(T& container, const int element) {
	IterT it = std::find(container.begin(), container.end(), element);

	if (it == container.end()) {
		throw std::out_of_range("Element not found");
	}
	return it;
}

#endif
