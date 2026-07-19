/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:44:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/19 17:53:34 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other): AMateria("cure") {}

Cure::~Cure() {}

Cure&	Cure::operator=(const Cure& rhs) {return (*this);}

Cure*	Cure::clone() const {return (new Cure(*this));}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}