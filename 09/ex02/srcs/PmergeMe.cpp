/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:43:26 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/23 15:40:13 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() : unsortedValues() {
}

PmergeMe::PmergeMe(int argc, char** argv) : unsortedValues() {
	this->unsortedValues = parseInput(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe& src) : unsortedValues(src.unsortedValues) {
}

PmergeMe::~PmergeMe() {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	if (this != &src) {
		this->unsortedValues = src.unsortedValues;
	}
	return *this;
}

std::string PmergeMe::trimInput(const std::string& input) {
	if (input.empty()) {
		throw std::invalid_argument("empty argument '" + input + "'.");
	}
	const char* whitespace = " \t\v\r\n";
	std::size_t start = input.find_first_not_of(whitespace);
	if (start == std::string::npos) {
		throw std::invalid_argument("invalid argument '" + input + "'.");
	}
	std::size_t end = input.find_last_not_of(whitespace);
	return input.substr(start, end - start + 1);
}

std::vector<int> PmergeMe::parseInput(int argc, char** argv) {
	std::vector<int> argVector;
	for (int i = 1; i < argc; ++ i) {
		std::string value = trimInput(argv[i]);
		char* end = NULL;
		errno = 0;
		long result = std::strtol(value.c_str(), &end, 10);
		if (end == value.c_str() || *end != '\0') {
			throw std::invalid_argument("invalid argument '" + value + "'.");
		}
		if (errno == ERANGE || result < 0 || result > std::numeric_limits<int>::max()) {
			throw std::invalid_argument("out of bounds int '" + value + "'.");
		}
		argVector.push_back(static_cast<int>(result));
	}
	std::cout << "Unsorted Vector:\n" << printContainer(argVector); //DEBUG
	return argVector;
}

std::vector<int> PmergeMe::insertionSortVector(const std::vector<int>& vector) {
	if (vector.size() < 2) {
		throw std::runtime_error("unexpected error, vector has less than 2 ints.");
	}
	std::vector<int> sortedVector = vector;
	std::vector<int>::iterator it = sortedVector.begin() + 1;
	for (; it != sortedVector.end(); ++it) {
		int key = *it;
		std::vector<int>::iterator insertPos = it;
		while (insertPos != sortedVector.begin() && *(insertPos - 1) > key) {
			*insertPos = *(insertPos - 1);
			std::advance(insertPos, -1);
			std::cout << printContainer(sortedVector); //DEBUG
		}
		*insertPos = key;
		std::cout << printContainer(sortedVector); //DEBUG
	}
	std::cout << "Sorted Vector:\n" << printContainer(sortedVector); //DEBUG
	return sortedVector;
}

std::deque<int> PmergeMe::insertionSortDeque(const std::deque<int>& deque) {
	if (deque.size() < 2) {
		throw std::runtime_error("unexpected error, deque has less than 2 ints.");
	}
	std::deque<int> sortedDeque = deque;
	std::deque<int>::iterator it = sortedDeque.begin() + 1;
	for (; it != sortedDeque.end(); ++it) {
		int key = *it;
		std::deque<int>::iterator insertPos = it;
		while (insertPos != sortedDeque.begin() && *(insertPos - 1) > key) {
			*insertPos = *(insertPos - 1);
			std::advance(insertPos, -1);
			std::cout << printContainer(sortedDeque); //DEBUG
		}
		*insertPos = key;
		std::cout << printContainer(sortedDeque); //DEBUG
	}
	std::cout << "Sorted Deque:\n" << printContainer(sortedDeque); //DEBUG
	return sortedDeque;
}

void PmergeMe::sortAndLog() {
	std::vector<int> sortedVector = insertionSortVector(this->unsortedValues);
	std::deque<int> unsortedDeque(this->unsortedValues.begin(), this->unsortedValues.end());
	std::cout << "Unsorted Deque:\n" << printContainer(unsortedDeque);
	std::deque<int> sortedDeque = insertionSortDeque(unsortedDeque);
}

template <typename T>
std::string PmergeMe::printContainer(const T& container) {
	if (container.empty()) {
		return "";
	}
	std::ostringstream oss;
	typename T::const_iterator it = container.begin();
	typename T::const_iterator end = container.end();
	for (; it != end; ++it) {
		std::string space = it != container.end() - 1 ? " " : "\n";
		oss << *it << space;
	}
	return oss.str();
}
