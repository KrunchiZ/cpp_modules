/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:44:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 22:22:27 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other): AMateria("ice") {}

Ice::~Ice() {}

Ice&	Ice::operator=(const Ice& rhs) {return (*this);}

Ice*	Ice::clone() const {return (new Ice(*this));}