/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 16:23:13 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/26 17:06:59 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	{
		std::cout << "--- Subject PDF Test ---\n\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Span = " << sp << '\n';
		std::cout << "Size = " << sp.size() << '\n';
		std::cout << "Shortest span = " << sp.shortestSpan() << '\n';
		std::cout << "Longest span = " << sp.longestSpan() << '\n';
	}
	std::cout << '\n';
	{
		std::cout << "--- Size 20 Span Test ---\n\n";
		Span sp = Span(20);
		sp.populateRandom(std::rand);
		std::cout << "Span = " << sp << '\n';
		std::cout << "Size = " << sp.size() << '\n';
		std::cout << "Shortest span = " << sp.shortestSpan() << '\n';
		std::cout << "Longest span = " << sp.longestSpan() << '\n';
	}
	std::cout << '\n';
	{
		std::cout << "--- Size 10k Span Test ---\n\n";
		Span sp = Span(10000);
		sp.populateRandom(std::rand);
		std::cout << "Size = " << sp.size() << '\n';
		std::cout << "sp[0] = " << sp[0] << '\n';
		std::cout << "sp[size - 1] = " << sp[sp.size() - 1] << '\n';
		std::cout << "Shortest span = " << sp.shortestSpan() << '\n';
		std::cout << "Longest span = " << sp.longestSpan() << '\n';
	}
	return (0);
}