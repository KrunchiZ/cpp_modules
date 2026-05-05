/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 20:53:23 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/05 22:53:40 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

const int	Fixed::s_fracBits = 8;

Fixed::Fixed()
	: m_rawBits(0)
{
	std::cout << "Default constructor called\n";
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
	this->m_rawBits = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits() const {return (m_rawBits);}

void	Fixed::setRawBits(int const raw) {m_rawBits = raw;}
