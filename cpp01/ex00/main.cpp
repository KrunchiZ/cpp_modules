/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:49:07 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/26 22:12:25 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

int	main(void)
{
	std::cout << "--- 'Zombie* foo = newZombie(\"foo\");' in main ---\n";
	Zombie* foo = newZombie("foo");
	std::cout << '\n';

	std::cout << "--- 'randomChump(\"chump\");' in main ---\n";
	randomChump("chump");
	std::cout << '\n';

	std::cout << "--- 'foo->announce();' in main ---\n";
	foo->announce();
	std::cout << '\n';

	std::cout << "--- 'delete foo;' in main ---\n";
	delete foo;
	return (0);
}
