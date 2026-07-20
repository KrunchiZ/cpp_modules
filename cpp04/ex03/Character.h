/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:48:54 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/20 18:23:30 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.h"
#include <string>

class AMateria;

class Character : public ICharacter
{
public:
	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& rhs);
	virtual ~Character();

	virtual const std::string& getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:
	std::string	m_name;
	AMateria*	m_inventory[4];
	int			m_inventoryCount;

	Character();
};

#endif