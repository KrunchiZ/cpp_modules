/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:26:14 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 15:53:52 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(const std::string& name = "Default");
	ScavTrap(const ScavTrap& other);
	virtual ~ScavTrap();

	ScavTrap&	operator=(const ScavTrap& other);
	bool		getGateKeeperMode() const;

	virtual void	attack(const std::string& target = "air");
	void			guardGate();

private:
	bool	m_gateKeeperMode;
};

std::ostream&	operator<<(std::ostream& out, const ScavTrap& rhs);

#endif
