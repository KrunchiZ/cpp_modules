/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:57:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 18:25:11 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Cat.h"
#include "Brain.h"
#include <iostream>
#include <string>
#include <cstdlib>

Cat::Cat()
	: Animal()
	, brain(new Brain())
{
	type = "Cat";
	std::cout << "Animal of type " << type << " has spawned.\n";
}

Cat::Cat(const Cat& other): brain(new Brain())
{
	std::cout << "Copying Animal of type " << other.type << ".\n";
	*this = other;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Animal of type " << type << " has been destroyed.\n";
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		type = rhs.type;
		if (brain)
			delete brain;
		brain = new Brain(*rhs.brain);
	}
	return (*this);
}

const std::string&	Cat::getType() const {return (type);}

void	Cat::makeSound() const
{
	std::cout << "Meow!\n";
}