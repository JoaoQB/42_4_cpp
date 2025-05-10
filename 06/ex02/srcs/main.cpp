/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:27:52 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/10 16:04:52 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
		return;
	} catch (...) {}

	std::cout << "Unknown";
}

void identify(Base* p) {
	if (!p) {
		std::cout << "NULL";
		return;
	}

	std::string result = "Unknown";

	if (dynamic_cast<A*>(p)) {
		result = "A";
	} else if (dynamic_cast<B*>(p)) {
		result = "B";
	} else if (dynamic_cast<C*>(p)) {
		result = "C";
	}

	std::cout << result;
}

Base* generate(void) {
	srand(time(0));
	const int random = rand() % 3;

	switch(random) {
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
	return NULL;
}

int main(void) {
	const int numPointers = 10;
	Base *ptr[numPointers] = { NULL };

	for (size_t i = 0; i < numPointers; ++i) {
		ptr[i] = generate();

		std::cout << "ptr[" << i << "] has class: ";
		identify(ptr[i]);
		std::cout << "\n";

		std::cout << "ref[" << i << "] has class: ";
		identify(*ptr[i]);
		std::cout << "\n";

		usleep(500000);
	}

	for (size_t i = 0; i < numPointers; ++i) {
		delete ptr[i];
	}
}
