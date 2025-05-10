/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:02:23 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/10 14:21:01 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main(void) {
	Data myData;

	std::cout << "[Initial myData]\n" << myData << "\n\n";

	myData.key = "secret";
	myData.value = "Shhhhh!";
	myData.isEncrypted = true;

	std::cout << "[Updated myData]\n" << myData << "\n\n";

	uintptr_t ptr = Serializer::serialize(&myData);
	std::cout << "[Serialized ptr]     " << ptr << "\n";

	Data* dataPtr = Serializer::deserialize(ptr);
	std::cout << "[Deserialized *ptr]\n" << *dataPtr << "\n\n";

	std::cout << "[Pointer address]    dataPtr: " << dataPtr << "\n";
	std::cout << "[Pointer address]    &myData: " << &myData << "\n";

	Data *myData2 = NULL;
	uintptr_t ptr2 = Serializer::serialize(myData2);
	Data* dataPtr2 = Serializer::deserialize(ptr2);
	std::cout << "[Pointer address]    dataPtr2: " << dataPtr2 << "\n";
	std::cout << "[Pointer address]    &myData2: " << myData2 << "\n";
}

