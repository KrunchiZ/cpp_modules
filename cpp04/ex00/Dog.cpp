/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:57:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 21:06:15 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Dog.h"
#include <iostream>
#include <string>

Dog::Dog(): Animal()
{
	type = "Dog";
	std::cout << "Animal of type " << type << " has spawned.\n";
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copying Animal of type " << other.type << ".\n";
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Animal of type " << type << " has been destroyed.\n";
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

const std::string&	Dog::getType() const {return (type);}

void	Dog::makeSound() const
{
	std::cout << "Woof!\n";
}