/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 20:53:23 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/07 17:13:00 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>
#include <cmath>

const int	Fixed::s_fracBits = 8;

Fixed::Fixed() : m_rawBits(0) {}
Fixed::Fixed(const int num) : m_rawBits(num << s_fracBits) {}
Fixed::Fixed(const float num) : m_rawBits(roundf(num * (1 << s_fracBits))) {}
Fixed::Fixed(const Fixed& other) {*this = other;}
Fixed::~Fixed() {}

int		Fixed::getRawBits() const {return (m_rawBits);}
void	Fixed::setRawBits(int const raw) {m_rawBits = raw;}

float	Fixed::toFloat() const
{
	return (static_cast<float>(m_rawBits) / (1 << s_fracBits));
}

int		Fixed::toInt() const
{
	return (m_rawBits >> s_fracBits);
}

/*  NOTE:******************************************************************** */
/*                                                                            */
/* Static Member Function                                                     */
/*                                                                            */
/* ************************************************************************** */

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	return ((f1 <= f2) ? f1 : f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	return ((f1 >= f2) ? f1 : f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return ((f1 <= f2) ? f1 : f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return ((f1 >= f2) ? f1 : f2);
}

/*  NOTE:******************************************************************** */
/*                                                                            */
/* Member Operator Function Overload                                          */
/*                                                                            */
/* ************************************************************************** */

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	m_rawBits = rhs.m_rawBits;
	return (*this);
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (m_rawBits > rhs.m_rawBits);
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (m_rawBits == rhs.m_rawBits);
}

bool	Fixed::operator<(const Fixed& rhs) const {return (rhs > *this);}
bool	Fixed::operator>=(const Fixed& rhs) const {return (!(*this < rhs));}
bool	Fixed::operator<=(const Fixed& rhs) const {return (!(*this > rhs));}
bool	Fixed::operator!=(const Fixed& rhs) const {return (!(*this == rhs));}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed	tmp;

	tmp.m_rawBits = m_rawBits + rhs.m_rawBits;
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed	tmp;

	tmp.m_rawBits = m_rawBits - rhs.m_rawBits;
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed	tmp;

	tmp.m_rawBits = m_rawBits * rhs.m_rawBits >> s_fracBits;
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed	tmp;

	tmp.m_rawBits = (m_rawBits << s_fracBits) / rhs.m_rawBits;
	return (tmp);
}

Fixed&	Fixed::operator++()
{
	++m_rawBits;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	--m_rawBits;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	++m_rawBits;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--m_rawBits;
	return (tmp);
}

/*  NOTE:******************************************************************** */
/*                                                                            */
/* Non-member Operator Function Overload                                      */
/*                                                                            */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
