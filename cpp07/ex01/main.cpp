/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:48:56 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/11 16:22:55 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype>

template <typename T>
void	print(const T& n)
{
	std::cout << n << " ";
}

void	bitshift(int& n)
{
	n <<= 1;
}

void	strToUpper(std::string& c)
{
	for (size_t i = 0; i < c.length(); ++i)
	{
		c[i] = std::toupper(static_cast<unsigned char>(c[i]));
	}
}

int	main()
{
	{
		int array[5] = {1, 2, 3, 4, 5};
		std::cout << "array = { ";
		::iter(array, 5, print<int>);
		std::cout << "}\nBitshifting << 1\n";
		::iter(array, 5, bitshift);
		std::cout << "array = { ";
		::iter(array, 5, print<int>);
		std::cout << "}\n";
	}
	std::cout << "--------------------\n";
	{
		std::string array[5] = {"hello", "world", "this", "is", "iter"};
		std::cout << "array = \"";
		::iter(array, 5, print<std::string>);
		std::cout << "\"\ntoUpper\n";
		::iter(array, 5, strToUpper);
		std::cout << "array = \"";
		::iter(array, 5, print<std::string>);
		std::cout << "\"\n";
	}
	return (0);
}