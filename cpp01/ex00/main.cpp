/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:49:07 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/26 21:51:16 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

int	main(void)
{
	Zombie* foo = newZombie("foo");

	randomChump("chump");
	foo->announce();
	delete foo;
	return (0);
}
