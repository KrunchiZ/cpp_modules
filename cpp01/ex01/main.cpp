/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:49:07 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 02:35:59 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

int	main(void)
{
	std::cout << "--- 'Zombie* horde = zombieHorde(5, \"Foo\");' ---\n"
		<< "--- Default Constructor will be called ---\n"
		<< "--- Foo will be set using setName ---\n";
	Zombie* horde = zombieHorde(5, "Foo");
	std::cout << '\n';

	std::cout << "--- Calling horde[i]->announce() for i = 0, i < 5 ---\n";
	for (int i = 0; i < 5; ++i)
		horde[i].announce();
	std::cout << '\n';

	std::cout << "--- 'delete[] horde;' ---\n";
	delete[] horde;
	return (0);
}
