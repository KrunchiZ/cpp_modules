/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 01:26:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/10 01:36:39 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int	main(void)
{
	ClapTrap	foo("Foo");

	for (int i = 0; i < 7; ++i)
		foo.attack("air");
	foo.beRepaired(1);
	foo.attack("Foo");
	foo.attack();
	foo.beRepaired(1);
	foo.attack("something");
	return (0);
}
