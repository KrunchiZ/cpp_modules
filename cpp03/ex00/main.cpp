/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 01:26:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 16:42:11 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>

int	main(void)
{
	ClapTrap	foo("Foo");

	for (int i = 0; i < 7; ++i)
		foo.attack();
	std::cout << foo;

	std::cout << "\nbar(foo), then setName(\"Bar\")\n\n";
	ClapTrap	bar(foo);
	bar.setName("Bar");

	std::cout << "foo attack again\n";
	foo.attack();
	foo.attack();
	foo.beRepaired(1);
	std::cout << foo;
	foo.beRepaired(1);
	foo.attack();

	std::cout << "\n" << bar;
	bar.attack();
	std::cout << bar;
	return (0);
}
