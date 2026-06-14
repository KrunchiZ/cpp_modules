/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:26:14 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 19:52:39 by kchiang          ###   ########.fr       */
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
	virtual ~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& other);

	const std::string&	getName() const;
	const unsigned int&	getHitPoints() const;
	const unsigned int&	getEnergyPoints() const;
	const unsigned int&	getAttackDamage() const;

	void	setName(const std::string& newName);

	virtual void	attack(const std::string& target = "air");
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);

protected:
	std::string		m_name;
	unsigned int	m_hitPoints;
	unsigned int	m_energyPoints;
	unsigned int	m_attackDamage;
};

std::ostream&	operator<<(std::ostream& out, const ClapTrap& rhs);

#endif
