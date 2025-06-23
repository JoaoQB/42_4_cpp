/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:42:45 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/23 15:35:10 by jqueijo-         ###   ########.fr       */
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

class PmergeMe {
	public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& src);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& src);

		void sortAndLog();

	private:
		std::vector<int> unsortedValues;
		PmergeMe();

		std::string trimInput(const std::string& input);
		std::vector<int> parseInput(int argc, char** argv);

		std::vector<int> insertionSortVector(const std::vector<int>& vector);
		std::vector<int> mergeSortVector(const std::vector<int>& vector);

		std::deque<int> insertionSortDeque(const std::deque<int>& deque);
		std::deque<int> mergeSortDeque(const std::deque<int>& deque);

		template <typename T>
		std::string printContainer(const T& container);
};


#endif
