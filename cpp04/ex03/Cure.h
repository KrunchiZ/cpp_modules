/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:40:29 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/19 17:53:16 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include "AMateria.h"
#include "ICharacter.h"
#include <string>

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& rhs);
	virtual ~Cure();
	
	const std::string& getType() const;
	
	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif