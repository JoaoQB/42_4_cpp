/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:24:28 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/10 19:10:23 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <iostream>
#include <string>

template< typename T >
void printWhatever(T& x) {
	std::cout << "[const] " << x << "\n";
}

void printLength(const std::string& str) {
	std::cout << "[length] \"" << str << "\" has " << str.size() << " characters\n";
}

void doubleValue(int& x) {
	x *= 2;
}

void appendSuffix(std::string& str) {
	str += "_suffix";
}

int main() {
	int numbers[] = {1, 2, 3, 4};
	std::cout << "Initial numbers:\n";
	iter(numbers, 4, printWhatever<int>);
	std::cout << "After doubling:\n";
	iter(numbers, 4, doubleValue);
	iter(numbers, 4, printWhatever<const int>);

	std::cout << "\n---\n";

	std::string names[] = {"alice", "bob", "carol"};
	std::cout << "Original names:\n";
	iter(names, 3, printLength);
	iter(names, 3, appendSuffix);
	std::cout << "Modified names:\n";
	iter(names, 3, printLength);

	return 0;
}
