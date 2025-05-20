/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:42:03 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/20 12:00:39 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() : maxSize(0), intVector() {
}

Span::Span(const unsigned int N) : maxSize(N), intVector() {
}

Span::Span(const Span& src) : maxSize(src.maxSize), intVector(src.intVector) {
}

Span::~Span() {
}

Span& Span::operator=(const Span &src) {
	if (this != &src) {
		this->maxSize = src.maxSize;
		this->intVector = src.intVector;
	}
	return *this;
}

void Span::addNumber(const int number) {
	if (this->intVector.size() == this->maxSize) {
		throw std::length_error("Vector full");
	}
	this->intVector.insert(this->intVector.end(), number);
}

long Span::shortestSpan() const {
	if (this->intVector.size() <= 1) {
		throw std::logic_error("Cannot compute span: not enough elements.");
	}
	std::vector<int> tempVector = this->intVector;

	std::sort(tempVector.begin(), tempVector.end());

	std::vector<int>::const_iterator it = tempVector.begin();
	std::vector<int>::const_iterator last = tempVector.end() - 1;
	long shortestDistance = std::numeric_limits<long>::max();
	for ( ; it != last; ++it) {
		long span = *(it + 1) - *it;
		if (span < shortestDistance) {
			shortestDistance = span;
		}
	}
	return shortestDistance;
}

long Span::longestSpan() const {
	if (this->intVector.size() <= 1) {
		throw std::logic_error("Cannot compute span: not enough elements.");
	}
	long min = *std::min_element(this->intVector.begin(), this->intVector.end());
	long max = *std::max_element(this->intVector.begin(), this->intVector.end());
	return max - min;
}

void Span::addRandomNumbers(const unsigned int N) {
	srand(time(0));
	for (unsigned int i = 0; i < N; ++i) {
		int random = rand();
		addNumber(random);
	}
}

void Span::printVector() const {
	std::vector<int>::const_iterator it = this->intVector.begin();
	if (it == this->intVector.end()) {
		std::cout << "Empty vector\n\n";
		return ;
	}
	for ( ; it != this->intVector.end(); ++it) {
		std::cout << "Number: " << *it << " , at index: "
			<< (it - this->intVector.begin()) << "\n";
	}
	std::cout << "\n";
}
