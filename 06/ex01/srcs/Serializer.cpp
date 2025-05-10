/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:55:08 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/10 14:16:16 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	if (!ptr) {
		std::cerr << "Warning: Attempted to serialize a null pointer.\n";
		return 0;
	}
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	if (raw == 0) {
		std::cerr << "Warning: Attempted to deserialize a null address.\n";
		return NULL;
	}
	return reinterpret_cast<Data*>(raw);
}
