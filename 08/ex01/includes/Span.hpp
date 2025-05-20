/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:31:59 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/20 12:01:50 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <list>
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <limits>
# include <ctime>

class Span {
	public:
		Span(const unsigned int N);
		Span(const Span& src);
		~Span();
		Span& operator=(const Span& src);

		void addNumber(const int number);
		long shortestSpan() const;
		long longestSpan() const;

		template <typename Container>
		void addRange(typename Container::const_iterator begin,
			typename Container::const_iterator end);

		void addRandomNumbers(const unsigned int N);
		void printVector() const;

	private:
		unsigned int maxSize;
		std::vector<int> intVector;

		Span();
};

#include "Span.tpp"
#endif
