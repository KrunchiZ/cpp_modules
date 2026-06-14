/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:30:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 15:26:36 by kchiang          ###   ########.fr       */
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
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	cout << "ScavTrap " << getName() << " has spawned with " << getHitPoints()
		<< " hit points, " << getEnergyPoints() << " energy points and "
		<< getAttackDamage() << " attack damage! Currently ";
	if (!m_gateKeeperMode)
		cout << "not ";
	cout << "on Gate Keeper duty!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {}

ScavTrap::~ScavTrap() {cout << "ScavTrap " << getName() << " has despawned!\n";}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

void	ScavTrap::attack(const string& target)
{
	if (getEnergyPoints())
	{
		cout << "ScavTrap " << getName() << " attacks " << target
			<< ", causing " << getAttackDamage() << " points of damage!\n";
		setEnergyPoints(getEnergyPoints() - 1);
		if (target == getName())
			takeDamage(getAttackDamage());
	}
	else
		cout << "ScavTrap " << getName()
			<< " ran out of energy points! Attack failed!\n";
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount)
	{
		cout << "ScavTrap " << getName() << " has taken " << amount
			<< " points of damage!\n";
		setHitPoints(getHitPoints() - amount);
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints())
	{
		cout << "ScavTrap " << getName() << " repairs itself and regains "
			<< amount << " hit points!\n";
		setEnergyPoints(getEnergyPoints() - 1);
		setHitPoints(getHitPoints() + amount);
	}
	else
		cout << "ScavTrap " << getName()
			<< " ran out of energy points! Repair failed!\n";
}

bool	ScavTrap::getGateKeeperMode() const {return (m_gateKeeperMode);}

void	ScavTrap::guardGate()
{
	m_gateKeeperMode = true;
	cout << "ScavTrap " << getName() << " has started Gate Keeper duty.\n";
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
