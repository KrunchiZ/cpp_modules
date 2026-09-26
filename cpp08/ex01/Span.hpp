/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:18:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/26 16:56:15 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
public:
	Span(unsigned int n = 0);
	Span(const Span& other);
	Span&	operator=(const Span& rhs);
	~Span();

	const unsigned int&	size() const;

	void	addNumber(int number);

	int&		operator[](const int& index);
	const int&	operator[](const int& index) const;
	int	shortestSpan() const;
	int	longestSpan() const;

	template <typename Function>
	void	populateRandom(Function func)
	{
		size_t current_size = m_vector.size();
		if (current_size >= m_size)
			return ;
		for (; current_size < m_size; ++current_size)
			m_vector.push_back(func());
	}

private:
	std::vector<int>	m_vector;
	unsigned int		m_size;
};

std::ostream&	operator<<(std::ostream& out, const Span& span);

#endif