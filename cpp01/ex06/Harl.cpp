/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:46:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/28 02:53:15 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include <string>
#include <iostream>

Harl::Harl() {std::cout << "Harl has entered the chat.\n";}
Harl::~Harl() {std::cout << "Harl has left the chat.\n";}

void	Harl::debug(void) {std::cout << "This is a DEBUG complain\n";}
void	Harl::info(void) {std::cout << "This is a INFO complain.\n";}
void	Harl::warning(void) {std::cout << "This is a WARNING complain\n";}
void	Harl::error(void) {std::cout << "This is a ERROR complain\n";}

void	Harl::complain(std::string level)
{
	const std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break ;
		++i;
	}
	switch(i)
	{
		case 0:
			debug();
			__attribute__((fallthrough));
		case 1:
			info();
			__attribute__((fallthrough));
		case 2:
			warning();
			__attribute__((fallthrough));
		case 3:
			error();
			return ;
		default:
			std::cout << "Just some trivial things\n";
			return ;
	}
}
