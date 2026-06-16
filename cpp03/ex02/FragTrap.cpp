/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:30:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/16 17:22:56 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include "ClapTrap.h"
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
