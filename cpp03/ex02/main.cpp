/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 01:26:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 20:11:35 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include <iostream>

int	main(void)
{
	FragTrap	foo("Foo");

	foo.attack();
	std::cout << foo;
	foo.takeDamage(20);
	std::cout << foo;
	foo.highFivesGuys();
	foo.beRepaired(20);
	std::cout << foo;

	std::cout << "\n// ClapTrap* bar(new FragTrap(\"Bar\"))\n"
		<< "// Base Class Pointer has no access to derived class member\n"
		<< "// without static casting it to derived class pointer\n\n";
	ClapTrap*	bar(new FragTrap("Bar"));
	bar->attack();
	static_cast<FragTrap*>(bar)->highFivesGuys();
	std::cout << static_cast<FragTrap&>(*bar);
	delete bar;
	return (0);
}
