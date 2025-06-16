/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:05:14 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/20 13:26:51 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

template <typename Container>
void test_container(Container& cont, const std::string& name)
{
	std::cout << "Testing " << name << ":\n";

	// push equivalent
	cont.push_back(5);
	cont.push_back(17);

	// print last element (top/back)
	std::cout << cont.back() << std::endl;

	// pop equivalent
	cont.pop_back();

	// print size
	std::cout << cont.size() << std::endl;

	cont.push_back(3);
	cont.push_back(5);
	cont.push_back(737);
	cont.push_back(0);

	// iterate and print elements
	typename Container::iterator it = cont.begin();
	typename Container::iterator ite = cont.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
}

int main()
{
	MutantStack<int> mstack;

	std::cout << "Testing MutantStack:\n";

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	// Now test std::list<int>
	std::list<int> lst;
	test_container(lst, "std::list");

	// Now test std::vector<int>
	std::vector<int> vec;
	test_container(vec, "std::vector");

	return 0;
}
