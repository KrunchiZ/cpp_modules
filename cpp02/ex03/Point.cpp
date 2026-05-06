/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:06:58 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/06 17:08:53 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include "Point.h"

Point::Point()
	: x(0), y(0)
{
}

Point::Point(const float f1, const float f2)
	: x(f1), y(f2)
{
}

Point::Point(const Point& other)
	: x(other.x), y(other.y)
{
}

Point::~Point()
{
}

Point&	Point::operator=(const Point&) {return (*this);}

const Fixed&	Point::getX() {return (this->x);}
const Fixed&	Point::getY() {return (this->y);}
