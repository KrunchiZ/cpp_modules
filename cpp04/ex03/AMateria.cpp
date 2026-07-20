/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:44:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/20 18:25:40 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"
#include "ICharacter.h"
#include <string>

AMateria::AMateria() {}

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

const std::string&	AMateria::getType() const {return (type);}

void	AMateria::use(ICharacter& target) {(void)target;}