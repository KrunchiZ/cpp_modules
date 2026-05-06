/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:01:56 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/06 16:07:50 by kchiang          ###   ########.fr       */
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

	Point&	operator=(const Point& rhs);

private:
	const Fixed	x;
	const Fixed	y;
};

#endif
