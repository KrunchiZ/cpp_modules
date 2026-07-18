/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:57:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 17:00:07 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal(): type("WrongBase")
{
	std::cout << "Animal of type " << type << " has spawned.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {*this = other;}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Animal of type " << type << " has been destroyed.\n";
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

const std::string&	WrongAnimal::getType() const {return (type);}

void	WrongAnimal::makeSound() const
{
	std::cout << "Some generic animal sound!\n";
}