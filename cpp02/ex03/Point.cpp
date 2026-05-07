/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:06:58 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/07 17:12:03 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include "Point.h"

Point::Point() : x(0), y(0) {}
Point::Point(const float f1, const float f2) : x(f1), y(f2) {}
Point::Point(const Point& other) : x(other.x), y(other.y) {}
Point::~Point() {}

Point&	Point::operator=(const Point&) {return (*this);}

const Fixed&	Point::getX() const {return (this->x);}
const Fixed&	Point::getY() const {return (this->y);}

std::ostream&	operator<<(std::ostream& out, const Point& point)
{
	out << '(' << point.getX().toFloat() << ", " << point.getY().toFloat()
		<< ')';
	return (out);
}

bool	operator==(const Point& lhs, const Point& rhs)
{
	return (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY());
}

bool	operator!=(const Point& lhs, const Point& rhs)
{
	return (!(lhs == rhs));
}
