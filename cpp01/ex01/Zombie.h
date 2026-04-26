/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:26:55 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 02:30:15 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
public:
	Zombie(const std::string& str = "default");
	~Zombie();

	void	setName(const std::string& str);
	void	announce(void);

private:
	std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
