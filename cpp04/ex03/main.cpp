/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:20:55 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/21 22:29:30 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.h"
#include "MateriaSource.h"
#include "ICharacter.h"
#include "Character.h"
#include "AMateria.h"
#include "Ice.h"
#include "Cure.h"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	me->unequip(1);
	bob->equip(tmp);
	bob->use(0, *me);
	bob->unequip(0);

	delete bob;
	delete me;
	delete src;
	delete tmp;

	return 0;
}