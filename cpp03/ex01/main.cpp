/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 01:26:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 16:49:26 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>

int	main(void)
{
	ScavTrap	foo("Foo");

	foo.attack();
	std::cout << foo;
	foo.takeDamage(20);
	std::cout << foo;
	foo.guardGate();
	foo.beRepaired(20);
	std::cout << foo;

	std::cout << "\nbar(foo), then setName(\"Bar\")\n\n";
	ScavTrap	bar(foo);
	bar.setName("Bar");
	bar.attack();
	std::cout << bar;
	return (0);
}
