/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:57:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/23 18:58:02 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main()
{
	std::cout << "--- Testing easyfind with std:vector ---\n";
	const int arr[5] = { 1, 2, 3, 4, 5 };
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	std::cout << "Vector contents: ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	std::cout << "easyfind(vec, 3): ";
	std::vector<int>::const_iterator it = easyfind(vec, 3);
	if (it != vec.end())
		std::cout << "Found\n";
	else
		std::cout << "Not found\n";

	std::cout << "easyfind(vec, 6): ";
	std::vector<int>::const_iterator it_not_found = easyfind(vec, 6);
	if (it_not_found != vec.end())
		std::cout << "Found\n";
	else
		std::cout << "Not found\n";
}