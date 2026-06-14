/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 01:26:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 17:05:01 by kchiang          ###   ########.fr       */
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

	std::cout << "\nbar(foo), then setName(\"Bar\")\n\n";
	FragTrap	bar(foo);
	bar.setName("Bar");
	bar.attack();
	bar.highFivesGuys();
	std::cout << bar;
	return (0);
}
