/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:57:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 18:24:21 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"
#include "WrongCat.h"
#include <iostream>
#include <string>

WrongCat::WrongCat(): WrongAnimal()
{
	type = "WrongCat";
	std::cout << "Animal of type " << type << " has spawned.\n";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "Copying Animal of type " << other.type << ".\n";
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "Animal of type " << type << " has been destroyed.\n";
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
	{
		WrongAnimal::operator=(rhs);
		type = rhs.type;
	}
	return (*this);
}

const std::string&	WrongCat::getType() const {return (type);}

void	WrongCat::makeSound() const
{
	std::cout << "Meow!\n";
}