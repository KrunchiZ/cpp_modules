/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:55:08 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/06 21:51:24 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include <iostream>

bool	bsp(const Point a, const Point b, const Point c, const Point point);

namespace
{
void	printYes(const Point& a, const Point& b, const Point& c,
			const Point& point);
void	printNo(const Point& a, const Point& b, const Point& c,
			const Point& point);
}

int	main(void)
{
	const Point	a;
	const Point	b(1.0f, 2.0f);
	const Point c(3.0f, 0.0f);

	{
		const Point point(1.0f, 0.0f);
		if (bsp(a, b, c, point))
			printYes(a, b, c, point);
		else
			printNo(a, b, c, point);
	}
	{
		const Point point(1.5f, 0.5f);
		if (bsp(a, b, c, point))
			printYes(a, b, c, point);
		else
			printNo(a, b, c, point);
	}
	{
		const Point point(2.0f, -0.1f);
		if (bsp(a, b, c, point))
			printYes(a, b, c, point);
		else
			printNo(a, b, c, point);
	}
	return (0);
}

namespace
{
void	printYes(const Point& a, const Point& b, const Point& c,
			const Point& point)
{
	std::cout << point << " is within triangle [" << a << ", " << b
		<< ", " << c << "]\n";
}

void	printNo(const Point& a, const Point& b, const Point& c,
			const Point& point)
{
	std::cout << point << " is not within triangle [" << a << ", " << b
		<< ", " << c << "]\n";
}
}
