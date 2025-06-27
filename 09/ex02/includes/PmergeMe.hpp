/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:42:45 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/27 09:59:22 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <exception>
# include <cstdlib>
# include <cerrno>
# include <limits>
# include <ctime>

class PmergeMe {
	public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& src);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& src);

		void sortAndLog();
		void testInsertAndMerge() const;// DEBUG

	private:
		std::vector<int> unsortedValues;
		PmergeMe();

		std::string trimInput(const std::string& input) const;
		std::vector<int> parseInput(int argc, char** argv);

		std::vector<int> insertionSortVector(const std::vector<int>& vector) const;
		std::deque<int> insertionSortDeque(const std::deque<int>& deque) const;

		void mergeSortVector(std::vector<int>& vector) const;
		void mergeSortDeque(std::deque<int>& deque) const;

		std::vector<size_t> generateJacobsthalIndicesVector(size_t nbrOfElements) const;
		std::vector<int>::iterator binarySearchInsertPosVector(
			std::vector<int>& main,
			int key,
			size_t elementSize
		) const;
		void fillMainAndPendVector(
			const std::vector<int>& vector,
			std::vector<int>& main,
			std::vector<int>& pend,
			size_t elementSize,
			size_t elementCount
		) const;
		void fordJohnsonSortVector(std::vector<int>& vector, size_t elementSize);

		std::deque<size_t> generateJacobsthalIndicesDeque(size_t nbrOfElements) const;
		std::deque<int>::iterator binarySearchInsertPosDeque(
			std::deque<int>& main,
			int key,
			size_t elementSize
		) const;
		void fillMainAndPendDeque(
			const std::deque<int>& deque,
			std::deque<int>& main,
			std::deque<int>& pend,
			size_t elementSize,
			size_t elementCount
		) const;
		void fordJohnsonSortDeque(std::deque<int>& deque, size_t elementSize);

		void logTimeTaken(
			const std::clock_t& start,
			const std::clock_t& end,
			const std::string& containerLabel,
			int containerSize
		) const;

		template <typename T>
		std::string printContainer(const T& container) const;
};


#endif
