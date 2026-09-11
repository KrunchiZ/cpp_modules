/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 14:24:42 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/11 15:46:16 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
{
	if (&a == &b)
		return ;
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(T a, T b)
{
	return ((a <= b) ? a : b);
}

template <typename T>
T	max(T a, T b)
{
	return ((a >= b) ? a : b);
}

#endif