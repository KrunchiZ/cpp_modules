/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:30:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 17:17:20 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include "DiamondTrap.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	cout << "DiamondTrap " << m_name<< " has spawned with " << m_hitPoints
		<< " hit points, " << m_energyPoints << " energy points and "
		<< m_attackDamage << " attack damage!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other) {*this = other;}

DiamondTrap::~DiamondTrap() {cout << "DiamondTrap " << m_name<< " has despawned!\n";}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void	DiamondTrap::attack(const string& target)
{
	if (getEnergyPoints())
	{
		cout << "DiamondTrap " << m_name<< " attacks " << target
			<< ", causing " << m_attackDamage << " points of damage!\n";
		--m_energyPoints;
		if (target == m_name)
			takeDamage(m_attackDamage);
	}
	else
		cout << "DiamondTrap " << m_name
			<< " ran out of energy points! Attack failed!\n";
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (amount)
	{
		cout << "DiamondTrap " << m_name<< " has taken " << amount
			<< " points of damage!\n";
		if (m_hitPoints >= amount)
			m_hitPoints -= amount;
		else
			m_hitPoints = 0;
	}
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (m_energyPoints)
	{
		cout << "DiamondTrap " << m_name<< " repairs itself and regains "
			<< amount << " hit points!\n";
		--m_energyPoints;
		m_hitPoints += amount;
	}
	else
		cout << "DiamondTrap " << m_name
			<< " ran out of energy points! Repair failed!\n";
}

void	DiamondTrap::highFivesGuys()
{
	cout << "DiamondTrap " << m_name<< ": High five guys!\n";
}

std::ostream&	operator<<(std::ostream& out, const DiamondTrap& rhs)
{
	out << "DiamondTrap " << rhs.getName() << ": " << rhs.getHitPoints()
		<< " hit points, " << rhs.getEnergyPoints() << " energy points, "
		<< rhs.getAttackDamage() << " attack damage!\n";
	return (out);
}
