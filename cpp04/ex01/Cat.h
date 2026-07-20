/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:56:18 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/20 18:35:33 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include <string>

class Brain;

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &other);
	Cat& operator=(const Cat &rhs);
	virtual ~Cat();

	virtual void makeSound() const;
	virtual const std::string& getType() const;

private:
	Brain* brain;
};

#endif