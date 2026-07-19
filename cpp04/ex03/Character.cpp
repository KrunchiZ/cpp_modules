/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 20:54:56 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/19 21:16:49 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"
#include <string>
#include <cstdlib>

Character::Character() {}

Character::Character(const std::string& name = "Default")
	: m_name(name), m_inventoryCount(0)
{
	for (int i = 0; i < 4; ++i)
		m_inventory[i] = NULL;
}

Character::Character(const Character& other) {*this = other;}

Character::~Character()
{
	for (int i = 0; i < m_inventoryCount; ++i)
		if (m_inventory[i])
			delete m_inventory[i];
}

Character&	Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_inventoryCount = rhs.m_inventoryCount;
		for (int i = 0; i < 4; ++i)
		{
			if (m_inventory[i])
				delete m_inventory[i];
			m_inventory[i] = rhs.m_inventory[i] ?
				rhs.m_inventory[i]->clone() : NULL;
		}
	}
	return (*this);
}

const std::string&	Character::getName() const
{
	return (m_name);
}

void	Character::equip(AMateria* m)
{
	if (m_inventoryCount < 4 && m)
		m_inventory[m_inventoryCount++] = m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < m_inventoryCount)
	{
		for (int i = idx; i < m_inventoryCount - 1; ++i)
			m_inventory[i] = m_inventory[i + 1];
		m_inventory[--m_inventoryCount] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < m_inventoryCount && m_inventory[idx])
		m_inventory[idx]->use(target);
}