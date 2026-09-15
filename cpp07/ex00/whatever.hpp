/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 14:24:42 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/16 01:29:57 by kchiang          ###   ########.fr       */
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
const T&	min(const T& a, const T& b)
{
	return ((a <= b) ? a : b);
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return ((a >= b) ? a : b);
}

#endif