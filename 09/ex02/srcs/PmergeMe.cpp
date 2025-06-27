/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:43:26 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/27 10:02:26 by jqueijo-         ###   ########.fr       */
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

std::string PmergeMe::trimInput(const std::string& input) const {
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
	return argVector;
}

std::vector<int> PmergeMe::insertionSortVector(const std::vector<int>& vector) const {
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
		}
		*insertPos = key;
	}
	return sortedVector;
}

std::deque<int> PmergeMe::insertionSortDeque(const std::deque<int>& deque) const {
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
		}
		*insertPos = key;
	}
	return sortedDeque;
}

void PmergeMe::mergeSortVector(std::vector<int>& vector) const {
	if (vector.size() <= 1) {
		return ;
	}
	std::vector<int>::iterator mid = vector.begin() + (vector.size() / 2);
	std::vector<int> left(vector.begin(), mid);
	std::vector<int> right(mid, vector.end());
	mergeSortVector(left);
	mergeSortVector(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), vector.begin());
}

void PmergeMe::mergeSortDeque(std::deque<int>& deque) const {
	if (deque.size() <= 1) {
		return ;
	}
	std::deque<int>::iterator mid = deque.begin() + (deque.size() / 2);
	std::deque<int> left(deque.begin(), mid);
	std::deque<int> right(mid, deque.end());
	mergeSortDeque(left);
	mergeSortDeque(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), deque.begin());
}

std::vector<size_t> PmergeMe::generateJacobsthalIndicesVector(size_t nbrOfElements) const {
	std::vector<size_t> jacobIndices;
	size_t j1 = 0;
	size_t j2 = 1;
	while (j2 < nbrOfElements) {
		jacobIndices.push_back(j2);
		size_t next = j2 + 2 * j1;
		j1 = j2;
		j2 = next;
	}
	std::reverse(jacobIndices.begin(), jacobIndices.end());
	return jacobIndices;
}

std::vector<int>::iterator PmergeMe::binarySearchInsertPosVector(
	std::vector<int>& main,
	int key,
	size_t elementSize
) const {
	size_t groupCount = main.size() / elementSize;
	size_t leftGroup = 0;
	size_t rightGroup = groupCount;

	while (leftGroup < rightGroup) {
		size_t midGroup = (leftGroup + rightGroup) / 2;
		size_t midGroupOffset = midGroup * elementSize;
		size_t midKeyIndex = midGroupOffset + elementSize - 1;

		int midVal = *(main.begin() + midKeyIndex);

		if (midVal < key) {
			leftGroup = midGroup + 1;
		} else {
			rightGroup = midGroup;
		}
	}

	size_t insertOffset = leftGroup * elementSize;
	return main.begin() + insertOffset;
}

void PmergeMe::fillMainAndPendVector(
	const std::vector<int>& vector,
	std::vector<int>& main,
	std::vector<int>& pend,
	size_t elementSize,
	size_t elementCount
) const {
	// Insert b1 and a1 in main
	size_t endOfA1 = 2 * elementSize;
	main.insert(main.end(), vector.begin(), vector.begin() + endOfA1);

	// Insert rest of a's in main
	for (size_t i = 2; i < elementCount; ++i) {
		// a elements are always odd
		if (i % 2 == 1) {
			size_t start = i * elementSize;
			size_t end = start + elementSize;
			main.insert(main.end(), vector.begin() + start, vector.begin() + end);
		}
	}

	// Insert b's from b2 onward in pend
	for (size_t i = 2; i < elementCount; ++i) {
		// b elements are always even
		if (i % 2 == 0) {
			size_t start = i * elementSize;
			size_t end = start + elementSize;
			pend.insert(pend.end(), vector.begin() + start, vector.begin() + end);
		}
	}

	// Insert leftovers in main
	size_t leftoverStart = elementCount * elementSize;
	if (leftoverStart < vector.size()) {
		main.insert(main.end(), vector.begin() + leftoverStart, vector.end());
	}
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& vector, size_t elementSize) {
	size_t totalSize = vector.size();
	size_t elementCount = totalSize / elementSize;

	if (elementCount < 2){
		return ;
	}

	size_t pairSize = elementSize * 2;

	for (size_t i = 0; i + pairSize <= totalSize; i += pairSize) {
		std::vector<int>::iterator leftGroupIt = vector.begin() + i;
		std::vector<int>::iterator rightGroupIt = leftGroupIt + elementSize;
		size_t indexToCompare = elementSize - 1;
		if (*(leftGroupIt + indexToCompare) > *(rightGroupIt + indexToCompare)) {
			std::swap_ranges(leftGroupIt, rightGroupIt, rightGroupIt);
		}
	}

	fordJohnsonSortVector(vector, pairSize);

	std::vector<int> main;
	std::vector<int> pend;

	fillMainAndPendVector(vector, main, pend, elementSize, elementCount);

	// Generate reverse JacobsthalIndices
	size_t elementsInPend = pend.size() / elementSize;
	std::vector<size_t> insertOrder = generateJacobsthalIndicesVector(elementsInPend);

	// Keep track of what indices were inserted
	std::vector<bool> inserted(elementsInPend, false);

	// Insert jacobsthal indices from pend into main
	for (size_t i = 0; i < insertOrder.size(); ++i) {
		size_t index = insertOrder[i];
		if (index >= elementsInPend || inserted[index]) {
			continue ;
		}

		size_t start = index * elementSize;
		size_t end = start + elementSize;

		std::vector<int> group(pend.begin() + start, pend.begin() + end);
		int key = group[elementSize - 1];

		std::vector<int>::iterator insertPos = binarySearchInsertPosVector(main, key, elementSize);
		main.insert(insertPos, group.begin(), group.end());
		inserted[index] = true;
	}

	// Insert remaining pend in reverse order
	int elemInPend = static_cast<int>(elementsInPend);
	for (int i = elemInPend - 1; i >= 0; --i) {
		if (inserted[i]) {
			continue;
		}

		size_t start = i * elementSize;
		size_t end = start + elementSize;
		std::vector<int> group(pend.begin() + start, pend.begin() + end);
		int key = group[elementSize - 1];

		std::vector<int>::iterator insertPos = binarySearchInsertPosVector(main, key, elementSize);
		main.insert(insertPos, group.begin(), group.end());
	}

	// Insert main into vector.
	vector.assign(main.begin(), main.end());
}

std::deque<size_t> PmergeMe::generateJacobsthalIndicesDeque(size_t nbrOfElements) const {
	std::deque<size_t> jacobIndices;
	size_t j1 = 0;
	size_t j2 = 1;
	while (j2 < nbrOfElements) {
		jacobIndices.push_back(j2);
		size_t next = j2 + 2 * j1;
		j1 = j2;
		j2 = next;
	}
	std::reverse(jacobIndices.begin(), jacobIndices.end());
	return jacobIndices;
}

std::deque<int>::iterator PmergeMe::binarySearchInsertPosDeque(
	std::deque<int>& main,
	int key,
	size_t elementSize
) const {
	size_t groupCount = main.size() / elementSize;
	size_t leftGroup = 0;
	size_t rightGroup = groupCount;

	while (leftGroup < rightGroup) {
		size_t midGroup = (leftGroup + rightGroup) / 2;
		size_t midGroupOffset = midGroup * elementSize;
		size_t midKeyIndex = midGroupOffset + elementSize - 1;

		int midVal = *(main.begin() + midKeyIndex);

		if (midVal < key) {
			leftGroup = midGroup + 1;
		} else {
			rightGroup = midGroup;
		}
	}

	size_t insertOffset = leftGroup * elementSize;
	return main.begin() + insertOffset;
}

void PmergeMe::fillMainAndPendDeque(
	const std::deque<int>& deque,
	std::deque<int>& main,
	std::deque<int>& pend,
	size_t elementSize,
	size_t elementCount
) const {
	// Insert b1 and a1 in main
	size_t endOfA1 = 2 * elementSize;
	main.insert(main.end(), deque.begin(), deque.begin() + endOfA1);

	// Insert rest of a's in main
	for (size_t i = 2; i < elementCount; ++i) {
		// a elements are always odd
		if (i % 2 == 1) {
			size_t start = i * elementSize;
			size_t end = start + elementSize;
			main.insert(main.end(), deque.begin() + start, deque.begin() + end);
		}
	}

	// Insert b's from b2 onward in pend
	for (size_t i = 2; i < elementCount; ++i) {
		// b elements are always even
		if (i % 2 == 0) {
			size_t start = i * elementSize;
			size_t end = start + elementSize;
			pend.insert(pend.end(), deque.begin() + start, deque.begin() + end);
		}
	}

	// Insert leftovers in main
	size_t leftoverStart = elementCount * elementSize;
	if (leftoverStart < deque.size()) {
		main.insert(main.end(), deque.begin() + leftoverStart, deque.end());
	}
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& deque, size_t elementSize) {
	size_t totalSize = deque.size();
	size_t elementCount = totalSize / elementSize;

	if (elementCount < 2){
		return ;
	}

	size_t pairSize = elementSize * 2;

	for (size_t i = 0; i + pairSize <= totalSize; i += pairSize) {
		std::deque<int>::iterator leftGroupIt = deque.begin() + i;
		std::deque<int>::iterator rightGroupIt = leftGroupIt + elementSize;
		size_t indexToCompare = elementSize - 1;
		if (*(leftGroupIt + indexToCompare) > *(rightGroupIt + indexToCompare)) {
			std::swap_ranges(leftGroupIt, rightGroupIt, rightGroupIt);
		}
	}

	fordJohnsonSortDeque(deque, pairSize);

	std::deque<int> main;
	std::deque<int> pend;

	fillMainAndPendDeque(deque, main, pend, elementSize, elementCount);

	// Generate reverse JacobsthalIndices
	size_t elementsInPend = pend.size() / elementSize;
	std::deque<size_t> insertOrder = generateJacobsthalIndicesDeque(elementsInPend);

	// Keep track of what indices were inserted
	std::deque<bool> inserted(elementsInPend, false);

	// Insert jacobsthal indices from pend into main
	for (size_t i = 0; i < insertOrder.size(); ++i) {
		size_t index = insertOrder[i];
		if (index >= elementsInPend || inserted[index]) {
			continue ;
		}

		size_t start = index * elementSize;
		size_t end = start + elementSize;

		std::deque<int> group(pend.begin() + start, pend.begin() + end);
		int key = group[elementSize - 1];

		std::deque<int>::iterator insertPos = binarySearchInsertPosDeque(main, key, elementSize);
		main.insert(insertPos, group.begin(), group.end());
		inserted[index] = true;
	}

	// Insert remaining pend in reverse order
	int elemInPend = static_cast<int>(elementsInPend);
	for (int i = elemInPend - 1; i >= 0; --i) {
		if (inserted[i]) {
			continue;
		}

		size_t start = i * elementSize;
		size_t end = start + elementSize;
		std::deque<int> group(pend.begin() + start, pend.begin() + end);
		int key = group[elementSize - 1];

		std::deque<int>::iterator insertPos = binarySearchInsertPosDeque(main, key, elementSize);
		main.insert(insertPos, group.begin(), group.end());
	}

	// Insert main into deque.
	deque.assign(main.begin(), main.end());
}

void PmergeMe::logTimeTaken(
	const std::clock_t& start,
	const std::clock_t& end,
	const std::string& containerLabel,
	int containerSize
) const {
	const long MICROSECONDS_IN_SECOND = 1000000L;

	double time_taken_sec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	long time_taken_us = static_cast<long>(time_taken_sec * MICROSECONDS_IN_SECOND);

	std::cout << "Time to process a range of " << containerSize << " elements"
	" with std::" << containerLabel << " : " << time_taken_us << " us\n";
}

template <typename T>
std::string PmergeMe::printContainer(const T& container) const {
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

void PmergeMe::sortAndLog() {
	const std::vector<int>& unsortedVector = this->unsortedValues;
	std::vector<int> sortVector(unsortedVector);
	std::deque<int> sortDeque(unsortedVector.begin(), unsortedVector.end());
	size_t elementSize = 1;
	std::clock_t start, end;

	std::cout << "\nUnsorted Sequence:\n" << printContainer(unsortedVector) << "\n"; //DEBUG

	start = clock();
	fordJohnsonSortVector(sortVector, elementSize);
	end = clock();

	std::cout << "\nSorted Sequence:\n" << printContainer(sortVector) << "\n";
	logTimeTaken(start, end, "vector", sortVector.size());

	start = clock();
	fordJohnsonSortDeque(sortDeque, elementSize);
	end = clock();
	logTimeTaken(start, end, "deque", sortDeque.size());
}

void PmergeMe::testInsertAndMerge() const {
	const std::vector<int>& unsortedVector = this->unsortedValues;
	const std::deque<int> unsortedDeque(this->unsortedValues.begin(), this->unsortedValues.end());
	std::clock_t start, end;

	std::cout << "\nUnsorted Sequence:\n" << printContainer(unsortedVector) << "\n"; //DEBUG

	start = clock();
	std::vector<int> sortedInsertionVector = insertionSortVector(this->unsortedValues);
	end = clock();

	std::cout << "\nSorted Sequence:\n" << printContainer(sortedInsertionVector) << "\n"; //DEBUG

	std::cout << "\n========== INSERTION SORT ==========\n\n";
	logTimeTaken(start, end, "vector", sortedInsertionVector.size());


	// std::cout << "Unsorted Deque:\n" << printContainer(unsortedDeque) << "\n"; //DEBUG
	start = clock();
	std::deque<int> sortedInsertionDeque = insertionSortDeque(unsortedDeque);
	end = clock();
	logTimeTaken(start, end, "deque", sortedInsertionDeque.size());

	std::cout << "\n========== MERGE SORT ==========\n\n";
	// std::cout << "Unsorted Vector:\n" << printContainer(unsortedVector) << "\n"; //DEBUG
	std::vector<int> sortedMergeVector(unsortedVector);
	start = clock();
	mergeSortVector(sortedMergeVector);
	end = clock();
	logTimeTaken(start, end, "vector", sortedMergeVector.size());
	// std::cout << "\nSorted Vector:\n" << printContainer(sortedMergeVector) << "\n"; //DEBUG

	// std::cout << "Unsorted Deque:\n" << printContainer(unsortedDeque) << "\n"; //DEBUG
	std::deque<int> sortedMergeDeque(unsortedDeque);
	start = clock();
	mergeSortDeque(sortedMergeDeque);
	end = clock();
	logTimeTaken(start, end, "deque", sortedMergeDeque.size());
	// std::cout << "\nSorted Deque:\n" << printContainer(sortedMergeDeque) << "\n"; //DEBUG
}
