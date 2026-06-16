/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:26:14 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/16 17:03:47 by kchiang          ###   ########.fr       */
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
