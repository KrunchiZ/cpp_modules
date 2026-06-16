/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:26:14 by kchiang           #+#    #+#             */
/*   Updated: 2026/06/16 17:18:55 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"
#include <string>

class FragTrap : public ClapTrap
{
public:
	FragTrap(const std::string& name = "Default");
	FragTrap(const FragTrap& other);
	virtual ~FragTrap();

	FragTrap&	operator=(const FragTrap& other);

	void			highFivesGuys();
};

std::ostream&	operator<<(std::ostream& out, const FragTrap& rhs);

#endif
