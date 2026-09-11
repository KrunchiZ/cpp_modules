/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:26:16 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/11 18:12:07 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
private:
	T*				m_array;
	unsigned int	m_size;

public:
	Array() : m_array(new T), m_size(0) {}
	Array(unsigned int n) : m_array(new T[n]), m_size(n) {}
	~Array() {delete[] m_array;}

	Array(const Array& other)
		: m_array(new T[other.m_size]), m_size(other.m_size)
	{
		for (unsigned int i = 0; i < m_size; ++i)
			m_array[i] = other.m_array[i];
	}

	Array& operator=(const Array& rhs)
	{
		if (this != &rhs)
		{
			delete[] m_array;
			m_size = rhs.m_size;
			m_array = new T[m_size];
			for (unsigned int i = 0; i < m_size; ++i)
				m_array[i] = rhs.m_array[i];
		}
		return (*this);
	}

	const unsigned int& size() const {return (m_size);}

	T& operator[](const int& index)
	{
		if (index < 0 || static_cast<unsigned int>(index) >= m_size)
			throw (std::out_of_range("Index out of range"));
		return (m_array[index]);
	}

	const T& operator[](const int& index) const
	{
		if (index < 0 || static_cast<unsigned int>(index) >= m_size)
			throw (std::out_of_range("Index out of range"));
		return (m_array[index]);
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr)
{
	for (unsigned int i = 0; i < arr.size(); ++i)
		out << arr[i] << " ";
	return (out);
}
// Can put this operator<< overload implementation into a tpp file
// and include it here at the bottom.
// 
// Example:
// template <typename T>
// std::ostream& operator<<(std::ostream& out, const Array<T>& arr);
// #include "Array.tpp"

#endif