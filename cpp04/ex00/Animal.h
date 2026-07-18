/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:56:18 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 17:27:02 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal
{
public:
	Animal();
	Animal(const Animal &other);
	virtual ~Animal();
	Animal& operator=(const Animal &rhs);

	virtual void makeSound() const;
	virtual const std::string& getType() const;

protected:
	std::string type;
};

#endif