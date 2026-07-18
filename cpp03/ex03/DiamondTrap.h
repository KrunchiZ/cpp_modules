/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:26:14 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 15:54:15 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.h"
#include "FragTrap.h"
#include <string>
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(const std::string& name = "Default");
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();

	DiamondTrap&	operator=(const DiamondTrap& other);

	virtual const std::string&	getName() const;

	void	setName(const std::string& newName);

	void			whoAmI();

private:
	std::string		m_name;
};

std::ostream&	operator<<(std::ostream& out, const DiamondTrap& rhs);

#endif
