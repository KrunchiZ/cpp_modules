/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:26:14 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/10 01:52:00 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
public:
	ClapTrap(const std::string& name = "Default");
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& rhs);

	void	attack(const std::string& target = "itself");
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	std::string		m_name;
	unsigned int	m_hitPoints;
	unsigned int	m_energyPoints;
	unsigned int	m_attackDamage;
};

#endif
