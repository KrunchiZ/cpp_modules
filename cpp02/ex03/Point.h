/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:01:56 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/06 01:35:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point
{
public:
	Point();
	Point(const float floatX, const float floatY);
	Point(const Point& other);
	~Point();

	const Fixed&	getX() const;
	const Fixed&	getY() const;

private:
	const Fixed	x;
	const Fixed	y;

	Point&	operator=(const Point&);
};

std::ostream&	operator<<(std::ostream& out, const Point& point);
bool			operator==(const Point& lhs, const Point& rhs);
bool			operator!=(const Point& lhs, const Point& rhs);

#endif
