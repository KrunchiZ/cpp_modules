/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:44:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/20 18:24:51 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"
#include "AMateria.h"
#include "ICharacter.h"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice&): AMateria("ice") {}

Ice::~Ice() {}

Ice&	Ice::operator=(const Ice&) {return (*this);}

Ice*	Ice::clone() const {return (new Ice(*this));}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}