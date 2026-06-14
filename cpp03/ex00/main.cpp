/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 01:26:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 14:52:34 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>

int	main(void)
{
	ClapTrap	foo("Foo");

	for (int i = 0; i < 7; ++i)
		foo.attack();
	std::cout << "\n" << foo;
	foo.beRepaired(1);
	foo.attack("Foo");
	foo.attack("Foo");
	std::cout << "\n" << foo;
	foo.beRepaired(1);
	foo.attack();
	return (0);
}
