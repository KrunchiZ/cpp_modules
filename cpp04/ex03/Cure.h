/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:40:29 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/20 18:23:14 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include "AMateria.h"
#include <string>

class ICharacter;

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure&);
	Cure& operator=(const Cure&);
	virtual ~Cure();
	
	const std::string& getType() const;
	
	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif