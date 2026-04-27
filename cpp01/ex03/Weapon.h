/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:12:37 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 15:57:01 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
public:
	Weapon(const std::string& newType = "fist");
	~Weapon();

	const std::string&	getType() const;
	void				setType(const std::string& newType);

private:
	std::string	type;
};

#endif
