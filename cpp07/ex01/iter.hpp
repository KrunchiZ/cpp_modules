/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:32:12 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/11 16:18:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename Function>
void	iter(T& array, const size_t size, Function fx)
{
	if (!size || !fx)
		return ;
	for (size_t i = 0; i < size; ++i)
	{
		fx(array[i]);
	}
}

#endif