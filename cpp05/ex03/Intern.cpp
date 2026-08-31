/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:41:16 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/31 11:47:54 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include <cstddef>

using std::string;

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) {return (*this);}

AForm*  Intern::makeForm(const string& form_name, const string& target)
{
	try
	{
		return (new ShrubberyCreationForm(form_name, target));
	}
	catch (const std::exception&) {}
	
	try
	{
		return (new RobotomyRequestForm(form_name, target));
	}
	catch (const std::exception&) {}

	try
	{
		return (new PresidentialPardonForm(form_name, target));
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Intern's failed to make form: " << ex.what() << '\n';
		return (NULL);
	}
}
