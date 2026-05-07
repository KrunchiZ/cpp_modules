/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 20:53:23 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/07 17:14:44 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>
#include <cmath>

const int	Fixed::s_fracBits = 8;

Fixed::Fixed()
	: m_rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num)
	: m_rawBits(num << s_fracBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num)
	: m_rawBits(roundf(num * (1 << s_fracBits)))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::~Fixed() {std::cout << "Destructor called\n";}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called\n";
	m_rawBits = rhs.m_rawBits;
	return (*this);
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (m_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	m_rawBits = raw;
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(m_rawBits) / (1 << s_fracBits));
}

int		Fixed::toInt() const
{
	return (m_rawBits >> s_fracBits);
}

/* ************************************************************************** */
/*                                                                            */
/* Non-member Operator Function Overload                                      */
/*                                                                            */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
