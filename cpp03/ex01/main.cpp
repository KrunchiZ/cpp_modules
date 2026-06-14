/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 01:26:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 15:28:07 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>

int	main(void)
{
	ScavTrap	foo("Foo");

	foo.attack();
	std::cout << "\n" << foo;
	foo.takeDamage(20);
	std::cout << "\n" << foo;
	foo.guardGate();
	foo.beRepaired(20);
	std::cout << "\n" << foo;
	return (0);
}
