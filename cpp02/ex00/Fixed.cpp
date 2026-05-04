/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 20:53:23 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/04 20:58:41 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const int	Fixed::s_fracBits = 8;

Fixed::Fixed(int rawBits)
	: m_rawBits(rawBits)
{
}

Fixed::Fixed(const Fixed& other) {*this = other;}

Fixed::~Fixed() {}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	this->m_rawBits = rhs.getRawBits();
	return (*this);
}
