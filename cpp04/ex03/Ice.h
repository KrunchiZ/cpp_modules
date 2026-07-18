/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:40:29 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 22:03:41 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include "AMateria.h"
#include "ICharacter.h"
#include <string>

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& rhs);
	virtual ~Ice();
	
	const std::string& getType() const;
	
	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};

#endif