/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:54:28 by jqueijo-          #+#    #+#             */
/*   Updated: 2025/06/22 17:35:13 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN()
	: inputExpression()
	, operandStack() {
}

RPN::RPN(const std::string& inputString)
	: inputExpression(inputString)
	, operandStack() {
	this->validateInputExpression();
}

RPN::RPN(const RPN& src)
	: inputExpression(src.inputExpression)
	, operandStack() {
}

RPN::~RPN() {
}

RPN& RPN::operator=(const RPN& src) {
	if (this != &src) {
		this->inputExpression = src.inputExpression;
		this->operandStack = src.operandStack;
	}
	return *this;
}

std::string RPN::trimInput(const std::string& input) {
	if (input.empty()) {
		throw std::invalid_argument("empty input");
	}
	const char* whitespace = " \t\v\r\n";
	std::size_t start = input.find_first_not_of(whitespace);
	if (start == std::string::npos) {
		throw std::invalid_argument("invalid input");
	}
	std::size_t end = input.find_last_not_of(whitespace);
	return input.substr(start, end - start + 1);
}

bool RPN::isOperator(const char c) {
	return c == '+' || c == '-' || c == '/' || c == '*';
}

void RPN::validateInputExpression() {
	const std::string& input = this->inputExpression;
	std::string trimmedInput = trimInput(input);
	std::istringstream inputStream(trimmedInput);
	std::string token;
	int operandCount = 0;
	while (inputStream >> token) {
		if (token.size() != 1) {
			throw std::invalid_argument("input must be space separated");
		}
		char c = token.at(0);
		if (std::isdigit(c)) {
			operandCount++;
		} else if (isOperator(c)) {
			if (operandCount < 2) {
				throw std::invalid_argument("not enough operands for operators");
			}
			operandCount--;
		} else {
			throw std::invalid_argument("input has invalid character");
		}
	}
	if (operandCount != 1) {
		throw std::invalid_argument("leftover operands or insufficient operators");
	}
}

int RPN::calculate(int leftOperand, int rightOperand, const char operatorType) {
	switch (operatorType) {
		case '+':
			return leftOperand + rightOperand;
		case '-':
			return leftOperand - rightOperand;
		case '/':
			if (rightOperand == 0) {
				throw std::invalid_argument("can't divide by 0");
			}
			return leftOperand / rightOperand;
		case '*':
			return leftOperand * rightOperand;
		default:
			throw std::runtime_error("unexpected error");
	}
}

void RPN::processExpression() {
	std::stack<int>& stack = this->operandStack;
	std::istringstream inputStream(this->inputExpression);
	std::string token;
	int result;
	while (inputStream >> token) {
		char c = token.at(0);
		if (isdigit(c)) {
			int operand = std::atoi(token.c_str());
			stack.push(operand);
		} else if (isOperator(c)) {
			if (stack.size() < 2) {
				throw std::runtime_error("unexpected error, not enough operands");
			}
			int rightOperand = stack.top();
			stack.pop();
			int leftOperand = stack.top();
			stack.pop();
			result = calculate(leftOperand, rightOperand, c);
			stack.push(result);
		}
	}
	if (stack.size() != 1) {
		throw std::runtime_error("unexpected error, too many operands");
	}
	result = stack.top();
	std::cout << result << std::endl;
	stack = std::stack<int>();
}
