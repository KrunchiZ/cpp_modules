/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:32:40 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 16:09:55 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <string>

class HumanB
{
public:
	HumanB(const std::string& givenName);
	~HumanB();

	void	setWeapon(Weapon& givenWeapon);
	void	attack();

private:
	HumanB();

	Weapon*		weapon;
	std::string	name;
};

#endif
