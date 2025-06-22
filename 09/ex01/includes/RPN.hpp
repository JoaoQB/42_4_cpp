/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:34:27 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/22 17:06:36 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <iostream>
# include <sstream>
# include <cstdlib>
// # include <exception>

class RPN {
	public:
		RPN(const std::string& inputString);
		RPN(const RPN& src);
		~RPN();
		RPN& operator=(const RPN& src);

		void processExpression();

	private:
		std::string inputExpression;
		std::stack<int> operandStack;
		RPN();

		std::string trimInput(const std::string& input);
		bool isOperator(const char c);
		void validateInputExpression();
		int calculate(int leftOperand, int rightOperand, const char operatorType);
};
#endif
