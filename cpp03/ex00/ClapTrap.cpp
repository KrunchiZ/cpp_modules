/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:30:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 14:51:17 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;

ClapTrap::ClapTrap(const std::string& name)
	: m_name(name)
	, m_hitPoints(10)
	, m_energyPoints(10)
	, m_attackDamage(0)
{
	cout << "ClapTrap " << m_name << " has spawned with " << m_hitPoints
		<< " hit points, " << m_energyPoints << " energy points and "
		<< m_attackDamage << " attack damage!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {*this = other;}

ClapTrap::~ClapTrap() {cout << "ClapTrap " << m_name << " has despawned!\n";}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_hitPoints = rhs.m_hitPoints;
		m_hitPoints = rhs.m_energyPoints;
		m_hitPoints = rhs.m_attackDamage;
	}
	return (*this);
}

const string&	ClapTrap::getName() const {return (m_name);}
const unsigned int&	ClapTrap::getHitPoints() const {return (m_hitPoints);}
const unsigned int&	ClapTrap::getEnergyPoints() const {return (m_energyPoints);}
const unsigned int&	ClapTrap::getAttackDamage() const {return (m_attackDamage);}

void	ClapTrap::setName(const string& newName)
{
	m_name = newName;
}

void	ClapTrap::setHitPoints(const unsigned int& hp) {m_hitPoints = hp;}
void	ClapTrap::setEnergyPoints(const unsigned int& ep) {m_energyPoints = ep;}
void	ClapTrap::setAttackDamage(const unsigned int& atkDmg) {m_attackDamage = atkDmg;}

void	ClapTrap::attack(const string& target)
{
	if (m_energyPoints)
	{
		cout << "ClapTrap " << m_name << " attacks " << target << ", causing "
			<< m_attackDamage << " points of damage!\n";
		--m_energyPoints;
		if (target == m_name)
			takeDamage(m_attackDamage);
	}
	else
		cout << "ClapTrap " << m_name
			<< " ran out of energy points! Attack failed!\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount)
	{
		cout << "ClapTrap " << m_name << " has taken " << amount
			<< " points of damage!\n";
		m_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energyPoints)
	{
		cout << "ClapTrap " << m_name << " repairs itself and regains "
			<< amount << " hit points!\n";
		--m_energyPoints;
		m_hitPoints += amount;
	}
	else
		cout << "ClapTrap " << m_name
			<< " ran out of energy points! Repair failed!\n";
}

std::ostream&	operator<<(std::ostream& out, const ClapTrap& rhs)
{
	out << "ClapTrap " << rhs.getName() << ": " << rhs.getHitPoints()
		<< " hit points, " << rhs.getEnergyPoints() << " energy points and "
		<< rhs.getAttackDamage() << " attack damage\n";
	return (out);
}
