/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 15:18:16 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/26 16:56:36 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

Span::Span(unsigned int n) : m_size(n) { m_vector.reserve(n); }
Span::Span(const Span &other) : m_vector(other.m_vector), m_size(other.m_size) {}
Span::~Span() {}

Span&	Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		m_vector = rhs.m_vector;
		m_size = rhs.m_size;
	}
	return (*this);
}

const unsigned int&	Span::size() const { return (m_size); }

int&		Span::operator[](const int &index) { return (m_vector.at(index)); }
const int&	Span::operator[](const int &index) const { return (m_vector.at(index)); }

void	Span::addNumber(int number)
{
	if (m_vector.size() >= m_size)
		throw std::length_error("Span is full.");
	m_vector.push_back(number);
}

int	Span::shortestSpan() const
{
	if (m_vector.size() < 2)
		throw std::logic_error("Logic error: Not enough numbers to find span.");

	int shortest_span = std::numeric_limits<int>::max();
	std::vector<int> sorted_vector = m_vector;
	std::sort(sorted_vector.begin(), sorted_vector.end());
	for (size_t i = 1; i < sorted_vector.size(); ++i)
	{
		int span = sorted_vector[i] - sorted_vector[i - 1];
		if (span < shortest_span)
			shortest_span = span;
	}
	return (shortest_span);
}

int	Span::longestSpan() const
{
	if (m_vector.size() < 2)
		throw std::logic_error("Logic error: Not enough numbers to find span.");
	return (*std::max_element(m_vector.begin(), m_vector.end()) -
		*std::min_element(m_vector.begin(), m_vector.end()));
}

std::ostream&	operator<<(std::ostream& out, const Span& span)
{
	out << "[ ";
	for (size_t i = 0; i < span.size(); ++i)
	{
		out << span[i];
		if (i < span.size() - 1)
			out << ", ";
	}
	out << " ]";
	return (out);
}