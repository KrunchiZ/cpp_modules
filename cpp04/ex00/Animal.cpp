/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:57:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 18:22:59 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include <string>
#include <iostream>

Animal::Animal(): type("Base")
{
	std::cout << "Animal of type " << type << " has spawned.\n";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copying Animal of type " << other.type << ".\n";
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Animal of type " << type << " has been destroyed.\n";
}

Animal&	Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

const std::string&	Animal::getType() const {return (type);}

void	Animal::makeSound() const
{
	std::cout << "Some generic animal sound!\n";
}