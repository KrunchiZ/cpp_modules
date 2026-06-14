/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:26:14 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 16:59:26 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"
#include <string>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(const std::string& name = "Default");
	ScavTrap(const ScavTrap& other);
	~ScavTrap();

	ScavTrap&	operator=(const ScavTrap& other);
	bool	getGateKeeperMode() const;

	void	attack(const std::string& target = "air");
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	guardGate();

private:
	bool	m_gateKeeperMode;
};

std::ostream&	operator<<(std::ostream& out, const ScavTrap& rhs);

#endif
