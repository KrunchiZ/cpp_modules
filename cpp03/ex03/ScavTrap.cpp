/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:30:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/16 17:29:49 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include "ClapTrap.h"
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
		m_gateKeeperMode = other.m_gateKeeperMode;
	return (*this);
}

void	ScavTrap::attack(const string& target)
{
	if (m_energyPoints)
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
