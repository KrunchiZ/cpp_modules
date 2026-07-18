/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:45:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 18:37:20 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>

int main()
{
	{
		std::cout <<"=== Test 1 ===\n";
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();
		const Dog		k(static_cast<const Dog&>(*j));
		const Cat		l(static_cast<const Cat&>(*i));

		delete j;
		delete i;
		
		k.makeSound();
		l.makeSound();
	}
	{
		std::cout << "\n\n=== Test 2 ===\n";
		const Animal* animals[10];

		for (int i = 0; i < 10; ++i)
		{
			if (i < 5)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
			std::cout << "\n";
		}
		std::cout << "\n--- Test 2 - Making Sounds ---";
		for (int i = 0; i < 10; ++i)
		{
			std::cout << "\nAnimal " << i + 1 << ": ";
			animals[i]->makeSound();
			delete animals[i];
		}
	}
	return (0);
}