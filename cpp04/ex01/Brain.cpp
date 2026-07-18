/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:19:59 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 17:25:28 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain has been created.\n";
}

Brain::Brain(const Brain& other) {*this = other;}

Brain::~Brain()
{
    std::cout << "Brain has been destroyed.\n";
}

Brain& Brain::operator=(const Brain& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = rhs.ideas[i];
    }
    return (*this);
}