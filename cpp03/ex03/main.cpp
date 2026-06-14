/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 01:26:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/15 00:00:19 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include <iostream>

int	main(void)
{
	DiamondTrap	foo("Foo");

	foo.attack();
	std::cout << foo;
	foo.takeDamage(20);
	foo.attack();
	foo.guardGate();
	foo.highFivesGuys();
	foo.whoAmI();
	foo.beRepaired(20);
	std::cout << foo;

	std::cout << "\nbar(foo), then setName(\"Bar\")\n\n";
	DiamondTrap	bar(foo);
	bar.setName("Bar");


	std::cout << "\n" << bar;
	bar.whoAmI();
	return (0);
}
