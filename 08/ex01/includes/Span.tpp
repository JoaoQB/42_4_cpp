/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:30:37 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/20 11:48:42 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename Container>
void Span::addRange(typename Container::const_iterator begin,
					typename Container::const_iterator end) {
	for (typename Container::const_iterator it = begin; it != end; ++it) {
		if (*it > std::numeric_limits<int>::max() ||
			*it < std::numeric_limits<int>::min()) {
			throw std::invalid_argument("Element out of int range");
		}
		addNumber(*it);
	}
}
