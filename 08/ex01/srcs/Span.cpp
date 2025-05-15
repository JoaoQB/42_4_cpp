/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:42:03 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/15 15:25:01 by jqueijo-         ###   ########.fr       */
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

double Span::shortestSpan() const {
	if (this->intVector.size() <= 1) {
		throw std::logic_error("Cannot compute span: not enough elements.");
	}
	std::vector<int> tempVector = this->intVector;

	// std::cout << "intVector before sorting:\n";// FOR DEBUG INIT
	// std::vector<int>::const_iterator tempIt = tempVector.begin();
	// for ( ; tempIt != tempVector.end(); ++tempIt) {
	// 	std::cout << "Number: " << *tempIt << " , at index: "
	// 		<< (tempIt - tempVector.begin()) << "\n";
	// }// FOR DEBUG END

	std::sort(tempVector.begin(), tempVector.end());

	// std::cout << "intVector after sorting:\n";// FOR DEBUG INIT
	// std::vector<int>::const_iterator it2 = tempVector.begin();
	// for ( ; it2 != tempVector.end(); ++it2) {
	// 	std::cout << "Number: " << *it2 << " , at index: "
	// 		<< (it2 - tempVector.begin()) << "\n";
	// }// FOR DEBUG END

	std::vector<int>::const_iterator it = tempVector.begin();
	std::vector<int>::const_iterator last = tempVector.end() - 1;
	double shortestDistance = std::numeric_limits<double>::max();
	for ( ; it != last; ++it) {
		double span = *(it + 1) - *it;
		if (span < shortestDistance) {
			shortestDistance = span;
		}
	}
	return shortestDistance;
}

double Span::longestSpan() const {
	if (this->intVector.size() <= 1) {
		throw std::logic_error("Cannot compute span: not enough elements.");
	}
	double min = *std::min_element(this->intVector.begin(), this->intVector.end());
	double max = *std::max_element(this->intVector.begin(), this->intVector.end());
	return max - min;
}

void Span::printVector() const { // FOR DEBUG
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

const std::vector<int>& Span::getVector() { // FOR DEBUG
	return this->intVector;
}
