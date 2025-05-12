/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:26:37 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/12 12:26:23 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename FuncT>
void iter(T* array, size_t size, FuncT func) {
	for (size_t i = 0; i < size; ++i) {
		func(array[i]);
	}
}

#endif
