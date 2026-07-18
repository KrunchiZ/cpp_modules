/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:57:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 17:34:21 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Dog.h"
#include "Brain.h"
#include <iostream>
#include <string>

Dog::Dog()
	: Animal()
	, brain(new Brain())
{
	type = "Dog";
	std::cout << "Animal of type " << type << " has spawned.\n";
}

Dog::Dog(const Dog& other) {*this = other;}

Dog::~Dog()
{
	delete brain;
	std::cout << "Animal of type " << type << " has been destroyed.\n";
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		type = rhs.type;
		delete brain;
		brain = new Brain(*rhs.brain);
	}
	return (*this);
}

const std::string&	Dog::getType() const {return (type);}

void	Dog::makeSound() const
{
	std::cout << "Woof!\n";
}