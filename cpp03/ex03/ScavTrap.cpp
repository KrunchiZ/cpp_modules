/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:30:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 16:46:43 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include "ScavTrap.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name), m_gateKeeperMode(false)
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	cout << "ScavTrap " << m_name<< " has spawned with " << m_hitPoints
		<< " hit points, " << m_energyPoints << " energy points and "
		<< m_attackDamage << " attack damage! Currently ";
	if (!m_gateKeeperMode)
		cout << "not ";
	cout << "on Gate Keeper duty!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {*this = other;}

ScavTrap::~ScavTrap() {cout << "ScavTrap " << m_name<< " has despawned!\n";}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		m_gateKeeperMode = other.m_gateKeeperMode;
	}
	return (*this);
}

void	ScavTrap::attack(const string& target)
{
	if (getEnergyPoints())
	{
		cout << "ScavTrap " << m_name<< " attacks " << target
			<< ", causing " << m_attackDamage << " points of damage!\n";
		--m_energyPoints;
		if (target == m_name)
			takeDamage(m_attackDamage);
	}
	else
		cout << "ScavTrap " << m_name
			<< " ran out of energy points! Attack failed!\n";
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount)
	{
		cout << "ScavTrap " << m_name<< " has taken " << amount
			<< " points of damage!\n";
		if (m_hitPoints >= amount)
			m_hitPoints -= amount;
		else
			m_hitPoints = 0;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (m_energyPoints)
	{
		cout << "ScavTrap " << m_name<< " repairs itself and regains "
			<< amount << " hit points!\n";
		--m_energyPoints;
		m_hitPoints += amount;
	}
	else
		cout << "ScavTrap " << m_name
			<< " ran out of energy points! Repair failed!\n";
}

bool	ScavTrap::getGateKeeperMode() const {return (m_gateKeeperMode);}

void	ScavTrap::guardGate()
{
	m_gateKeeperMode = true;
	cout << "ScavTrap " << m_name<< " has started Gate Keeper duty.\n";
}

std::ostream&	operator<<(std::ostream& out, const ScavTrap& rhs)
{
	out << "ScavTrap " << rhs.getName() << ": " << rhs.getHitPoints()
		<< " hit points, " << rhs.getEnergyPoints() << " energy points, "
		<< rhs.getAttackDamage() << " attack damage and currently ";
	if (!rhs.getGateKeeperMode())
		out << "not ";
	out << "on Gate Keeper duty\n";
	return (out);
}
