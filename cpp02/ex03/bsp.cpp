/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:08:32 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/06 18:15:41 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include "Fixed.h"

namespace
{
Fixed	calculateArea(const Point p1, const Point p2, const Point p3)
{
	Fixed	sum1(p1.getX() * p2.getY() + p2.getX() * p3.getY()
				+ p3.getX() * p1.getY());
	Fixed	sum2(p1.getY() * p2.getX() + p2.getY() * p3.getX()
				+ p3.getY() * p1.getX());

	if (sum2 > sum1)
		return ((sum2 - sum1) / Fixed(2));
	return ((sum1 - sum2) / Fixed(2));
}
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	if (point == a || point == b || point == c)
		return (false);

	const Fixed	triangleArea(calculateArea(a, b, c));
	const Fixed	areaABP(calculateArea(a, b, point));
	const Fixed	areaACP(calculateArea(a, c, point));
	const Fixed	areaBCP(calculateArea(b, c, point));

	if (areaABP.getRawBits() && areaACP.getRawBits() && areaBCP.getRawBits())
		return (areaABP + areaACP + areaBCP == triangleArea);
	return (false);
}
