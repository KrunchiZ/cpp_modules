/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:56:18 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 17:33:47 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog &rhs);
	virtual ~Dog();

	virtual void makeSound() const;
	virtual const std::string& getType() const;

private:
	Brain* brain;
};

#endif