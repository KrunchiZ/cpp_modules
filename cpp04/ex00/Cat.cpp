/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:57:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 16:42:11 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Cat.h"
#include <iostream>

Cat::Cat(): Animal()
{
	type = "Cat";
	std::cout << "Animal of type " << type << " has spawned.\n";
}

Cat::Cat(const Cat& other) {*this = other;}

Cat::~Cat()
{
	std::cout << "Animal of type " << type << " has been destroyed.\n";
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		type = rhs.type;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow!\n";
}