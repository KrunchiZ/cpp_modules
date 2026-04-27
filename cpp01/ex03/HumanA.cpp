/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:32:10 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 16:24:31 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include "HumanA.h"
#include <string>
#include <iostream>

using std::string;

HumanA::HumanA(const string& givenName, const Weapon& givenWeapon)
	: weapon(givenWeapon), name(givenName)
{
}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << name << " attacks with their "	<< weapon.getType() << '\n';
}
