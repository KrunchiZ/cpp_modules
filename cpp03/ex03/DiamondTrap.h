/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:26:14 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 17:20:55 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.h"
#include "FragTrap.h"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(const std::string& name = "Default");
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();

	DiamondTrap&	operator=(const DiamondTrap& other);

	void	attack(const std::string& target = "air");
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	whoAmI();
};

std::ostream&	operator<<(std::ostream& out, const DiamondTrap& rhs);

#endif
