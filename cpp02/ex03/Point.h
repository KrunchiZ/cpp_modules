/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:01:56 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/06 17:03:23 by kchiang          ###   ########.fr       */
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

	Point&	operator=(const Point&);

	const Fixed&	getX();
	const Fixed&	getY();

private:
	const Fixed	x;
	const Fixed	y;
};

#endif
