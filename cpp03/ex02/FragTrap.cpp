/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:30:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/14 20:16:44 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include "FragTrap.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	cout << "FragTrap " << m_name<< " has spawned with " << m_hitPoints
		<< " hit points, " << m_energyPoints << " energy points and "
		<< m_attackDamage << " attack damage!\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {*this = other;}

FragTrap::~FragTrap() {cout << "FragTrap " << m_name<< " has despawned!\n";}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void	FragTrap::attack(const string& target)
{
	if (m_energyPoints)
	{
		cout << "FragTrap " << m_name<< " attacks " << target
			<< ", causing " << m_attackDamage << " points of damage!\n";
		--m_energyPoints;
		if (target == m_name)
			takeDamage(m_attackDamage);
	}
	else
		cout << "FragTrap " << m_name
			<< " ran out of energy points! Attack failed!\n";
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (amount)
	{
		cout << "FragTrap " << m_name<< " has taken " << amount
			<< " points of damage!\n";
		if (m_hitPoints >= amount)
			m_hitPoints -= amount;
		else
			m_hitPoints = 0;
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (m_energyPoints)
	{
		cout << "FragTrap " << m_name<< " repairs itself and regains "
			<< amount << " hit points!\n";
		--m_energyPoints;
		m_hitPoints += amount;
	}
	else
		cout << "FragTrap " << m_name
			<< " ran out of energy points! Repair failed!\n";
}

void	FragTrap::highFivesGuys()
{
	cout << "FragTrap " << m_name<< ": High five guys!\n";
}

std::ostream&	operator<<(std::ostream& out, const FragTrap& rhs)
{
	out << "FragTrap " << rhs.getName() << ": " << rhs.getHitPoints()
		<< " hit points, " << rhs.getEnergyPoints() << " energy points, "
		<< rhs.getAttackDamage() << " attack damage!\n";
	return (out);
}
