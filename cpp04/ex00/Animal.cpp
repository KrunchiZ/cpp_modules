/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:57:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 16:06:31 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Animal::Animal(): m_type("Base") {}

Animal::Animal(const Animal& other) {*this = other;}

Animal::~Animal() {}

Animal&	Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
		m_type = rhs.m_type;
	return (*this);
}

void	Animal::makeSound() const {}