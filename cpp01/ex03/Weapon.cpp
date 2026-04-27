/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:22:48 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 14:28:49 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include <string>

using std::string;

Weapon::Weapon(const string& newType)
	: type(newType)
{
}

Weapon::~Weapon() {}

const string& Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(const string& newType)
{
	type = newType;
}
