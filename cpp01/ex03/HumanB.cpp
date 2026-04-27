/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:32:10 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 17:39:40 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include "HumanB.h"
#include <string>
#include <iostream>
#include <cstddef>

using std::string;

HumanB::HumanB(const string& givenName)
	: weapon(NULL), name(givenName)
{
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& givenWeapon)
{
	weapon = &givenWeapon;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their ";
	if (weapon)
		std::cout << weapon->getType() << '\n';
	else
		std::cout << "fist\n";
}
