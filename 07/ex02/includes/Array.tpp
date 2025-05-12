/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:00:27 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/12 16:09:29 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), array(new T[0]) {
}

template <typename T>
Array<T>::Array(const unsigned int n) : _size(n), array(new T[n]) {
	for (unsigned int i = 0; i < n; ++i) {
		array[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array& src) : _size(src._size), array(new T[src._size]) {
	for (unsigned int i = 0; i < _size; ++i) {
		this->array[i] = src.array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] this->array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src) {
	if (this != &src) {
		this->_size = src._size;
		delete[] this->array;
		this->array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i) {
			this->array[i] = src.array[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](const unsigned int index) {
	if (index >= this->_size) {
		throw std::out_of_range("Invalid index");
	}
	return array[index];
}

template <typename T>
const T& Array<T>::operator[](const unsigned int index) const {
	if (index >= this->_size) {
		throw std::out_of_range("Invalid index");
	}
	return array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}
