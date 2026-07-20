/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:44:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/20 18:24:41 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"
#include "AMateria.h"
#include "ICharacter.h"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure&): AMateria("cure") {}

Cure::~Cure() {}

Cure&	Cure::operator=(const Cure&) {return (*this);}

Cure*	Cure::clone() const {return (new Cure(*this));}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}