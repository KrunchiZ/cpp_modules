/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:09:51 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 13:11:50 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

int	main()
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");

		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
