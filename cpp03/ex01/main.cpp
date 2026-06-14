/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 01:26:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 20:08:14 by kchiang          ###   ########.fr       */
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

	std::cout << "\n// ClapTrap* bar(new ScavTrap(\"Bar\"))\n"
		<< "// Base Class Pointer has no access to derived class member\n"
		<< "// without static casting it to derived class pointer\n\n";
	ClapTrap*	bar(new ScavTrap("Bar"));
	bar->attack();
	static_cast<ScavTrap*>(bar)->guardGate();
	std::cout << static_cast<ScavTrap&>(*bar);
	delete bar;
	return (0);
}
