/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:30:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/15 00:02:19 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name")
	, ScavTrap(name)
	, FragTrap(name)
	, m_name(name)
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
	cout << "DiamondTrap " << m_name<< " has spawned with " << m_hitPoints
		<< " hit points, " << m_energyPoints << " energy points and "
		<< m_attackDamage << " attack damage! Currently ";
	if (!m_gateKeeperMode)
		cout << "not ";
	cout << "on Gate Keeper duty!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other)
	, ScavTrap(other)
	, FragTrap(other)
{
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap " << m_name<< " has despawned!\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		m_name = other.m_name;
	}
	return (*this);
}

const string&	DiamondTrap::getName() const {return (m_name);}

void	DiamondTrap::setName(const string& newName)
{
	m_name = newName;
	ClapTrap::m_name = newName + "_clap_name";
}

void	DiamondTrap::attack(const string& target)
{
	ScavTrap::attack(target);
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

void	DiamondTrap::whoAmI()
{
	cout << "Who am I? I am DiamondTrap " << m_name << ", aka "
		<< ClapTrap::m_name << "\n";
}

std::ostream&	operator<<(std::ostream& out, const DiamondTrap& rhs)
{
	out << "DiamondTrap " << rhs.getName() << (" (" + rhs.ClapTrap::getName())
		<< "): " << rhs.getHitPoints() << " hit points, "
		<< rhs.getEnergyPoints() << " energy points, "
		<< rhs.getAttackDamage() << " attack damage and currently ";
	if (!rhs.getGateKeeperMode())
		out << "not ";
	out << "on Gate Keeper duty\n";
	return (out);
}
