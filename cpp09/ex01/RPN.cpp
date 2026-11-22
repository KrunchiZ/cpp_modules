/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 13:40:03 by kchiang           #+#    #+#             */
/*   Updated: 2026/11/22 15:21:44 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>
#include <sstream>
#include <string>
#include <cctype>

namespace
{
	bool isOperator(char c)
	{
		return (c == '+' || c == '-' || c == '*' || c == '/');
	}
}

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) : m_operands(other.m_operands) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this == &other)
		return *this;
	m_operands = other.m_operands;
	return (*this);
}

int	RPN::evaluate(std::string expression)
{
	std::stringstream ss(expression);
	std::string token;
	while (ss >> token)
	{
		if (token.size() == 1 && !std::isdigit(token[0]))
		{
			if (!isOperator(token[0]))
				throw std::runtime_error("Error: Invalid operator '" + token + "'");
			if (m_operands.size() < 2)
				throw std::runtime_error("Error: Invalid RPN expression");
			performOperation(token[0]);
		}
		else
		{
			std::stringstream num_ss(token);
			int num;
			if (!(num_ss >> num) || !(num_ss.eof()))
				throw std::runtime_error("Error: Invalid token '" + token + "'");
			m_operands.push(num);
		}
	}

	if(!ss.eof())
		throw std::runtime_error("Error: Tokenization failed");
	if (m_operands.size() != 1)
		throw std::runtime_error("Error: Invalid RPN expression");

	int result = m_operands.top();
	m_operands.pop();
	return (result);
}

void	RPN::performOperation(char op)
{
	int right_operand = m_operands.top();
	m_operands.pop();
	int left_operand = m_operands.top();
	m_operands.pop();

	int result;
	switch (op)
	{
		case '+':
			result = left_operand + right_operand;
			break ;
		case '-':
			result = left_operand - right_operand;
			break ;
		case '*':
			result = left_operand * right_operand;
			break ;
		case '/':
			if (right_operand == 0)
				throw std::runtime_error("Error: Division by zero");
			result = left_operand / right_operand;
			break ;
		default:
			break ;
	}
	m_operands.push(result);
}