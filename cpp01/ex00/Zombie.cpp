/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:26:42 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/26 22:01:53 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <string>
#include <iostream>

Zombie::Zombie(const std::string& str)
	: name(str)
{
	std::cout << "Constructed Zombie " << name << '\n';
}

Zombie::~Zombie()
{
	std::cout << "Destroyed Zombie " << name << '\n';
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
