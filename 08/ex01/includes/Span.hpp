/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:31:59 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/05/15 15:18:56 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <limits>

class Span {
	public:
		Span(const unsigned int N);
		Span(const Span& src);
		~Span();
		Span& operator=(const Span& src);

		void addNumber(const int number);
		double shortestSpan() const;
		double longestSpan() const;
		void printVector() const; // FOR DEBUG
		const std::vector<int>& getVector(); // FOR DEBUG

	private:
		unsigned int maxSize;
		std::vector<int> intVector;

		Span();
};

#endif
