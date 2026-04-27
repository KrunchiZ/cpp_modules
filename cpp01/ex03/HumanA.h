/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:32:40 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 16:23:13 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <string>

class HumanA
{
public:
	HumanA(const std::string& givenName, const Weapon& givenWeapon);
	~HumanA();

	void	attack();

private:
	HumanA();

	const Weapon&	weapon;
	std::string		name;
};

#endif
