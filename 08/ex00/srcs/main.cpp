/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:12:20 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/20 11:03:19 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "../includes/easyfind.hpp"

int main(void) {
	// 1. Default constructor
	std::vector<int> v1;
	std::cout << "v1 (default constructor): size = " << v1.size() << std::endl;

	// 2. Fill constructor
	std::vector<int> v2(5, 42);
	std::cout << "v2 (fill constructor): ";
	for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// 3. Range constructor from raw array
	int arr[] = { 3, -10, 50, -10 };
	std::vector<int> v3(arr, arr + 4);
	std::cout << "v3 (range from array): ";
	for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// 4. Copy constructor
	std::vector<int> v4(v3);
	std::cout << "v4 (copy of v3): ";
	for (std::vector<int>::iterator it = v4.begin(); it != v4.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// 5. Range constructor from another vector using begin/end
	std::vector<int> v5(v3.begin(), v3.end());
	std::cout << "v5 (range from v3.begin(), v3.end()): ";
	for (std::vector<int>::iterator it = v5.begin(); it != v5.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// 6. String vector using fill constructor
	std::vector<std::string> cars(3, "DefaultCar");
	std::cout << "cars: ";
	for (std::vector<std::string>::iterator it = cars.begin(); it != cars.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// 7. Access tests
	std::cout << "v3[0]: " << v3[0] << std::endl;
	std::cout << "v3.front(): " << v3.front() << std::endl;
	std::cout << "v3.back(): " << v3.back() << std::endl;
	std::cout << "v3.at(2): " << v3.at(2) << std::endl;

	// // 8. Unsafe access
	// std::cout << "v3[10] (undefined behavior): " << v3[10] << std::endl;

	// 9. Safe access
	try {
		std::cout << "v3.at(10): " << v3.at(10) << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << "Exception on at(10): " << e.what() << std::endl;
	}

	int toFind = -10;
	try {
		std::vector<int>::iterator it = easyfind<std::vector<int>::iterator, std::vector<int> >(v3, toFind);
		std::cout << "Found " << *it << " at index: " << (it - v3.begin()) << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << toFind << " not found in vector." << std::endl;
	}

	return 0;
}
