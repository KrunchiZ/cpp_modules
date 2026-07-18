/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:26:14 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 15:54:10 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap
{
public:
	ClapTrap(const std::string& name = "Default");
	ClapTrap(const ClapTrap& other);
	virtual ~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& other);

	const unsigned int&	getHitPoints() const;
	const unsigned int&	getEnergyPoints() const;
	const unsigned int&	getAttackDamage() const;

	virtual const std::string&	getName() const;

	virtual void	setName(const std::string& newName);

	virtual void	attack(const std::string& target = "air");
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:
	std::string		m_name;
	unsigned int	m_hitPoints;
	unsigned int	m_energyPoints;
	unsigned int	m_attackDamage;
};

std::ostream&	operator<<(std::ostream& out, const ClapTrap& rhs);

#endif
