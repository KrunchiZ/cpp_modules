/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:40:29 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/20 18:22:41 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>

class ICharacter;

class AMateria
{
public:
	virtual ~AMateria();
	const std::string& getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string type;
	AMateria(const std::string& type);

private:
	AMateria();
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& rhs);
};

#endif