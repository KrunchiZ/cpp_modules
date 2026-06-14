/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:26:14 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 23:59:30 by kchiang          ###   ########.fr       */
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

	virtual const std::string&	getName() const;

	void	setName(const std::string& newName);

	virtual void	attack(const std::string& target = "air");
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
	void			whoAmI();

private:
	std::string		m_name;
};

std::ostream&	operator<<(std::ostream& out, const DiamondTrap& rhs);

#endif
