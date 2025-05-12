/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:24:38 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/12 15:51:48 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array {
	private:
		unsigned int _size;
		T* array;

	public:
		Array();
		Array(const unsigned int n);
		Array(const Array& src);
		~Array();

		Array& operator=(const Array& src);
		T& operator[](const unsigned int index);
		const T& operator[](const unsigned int index) const;
		unsigned int size() const;
};

#include "Array.tpp"
#endif
