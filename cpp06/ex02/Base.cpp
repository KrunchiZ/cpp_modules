/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:59:28 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/08 17:27:02 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base::Base() {}
Base::Base(const Base&) {}
Base::~Base() {}

Base*	Base::generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int selector = std::rand() % 3;
	if (selector == 0)
		return (new A());
	else if (selector == 1)
		return (new B());
	else
		return (new C());
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cerr << "Unknown Base type\n";
}

void	Base::identify(Base& p)
{
	try
	{
		A& a_ref = dynamic_cast<A&>(p);
		identify(&a_ref);
		return ;
	}
	catch (std::exception&) {}

	try
	{
		B& b_ref = dynamic_cast<B&>(p);
		identify(&b_ref);
		return ;
	}
	catch (std::exception&) {}

	try
	{
		C& c_ref = dynamic_cast<C&>(p);
		identify(&c_ref);
		return ;
	}
	catch (std::exception&)
	{
		std::cerr << "Unknown Base type\n";
	}
}