/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 11:20:23 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 22:38:50 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <exception>
#include <memory>
#include <cstddef>

using std::cout;

typedef ShrubberyCreationForm	SForm;
typedef RobotomyRequestForm		RForm;
typedef PresidentialPardonForm	PForm;

int main()
{
	Intern	internFoo;
	AForm*	form1;

	// will throw exception
	form1 = internFoo.makeForm("PresidentialPardonForm", "Peter");
	cout << form1 << '\n';

	// successful creation
	form1 = internFoo.makeForm("Presidential Pardon", "Peter");
	cout << form1 << '\n';

	if (form1 == NULL)
		return (0);

	std::auto_ptr<AForm>	form1_ptr(form1);
	Bureaucrat				chiang("Chiang", 1);	

	cout << chiang << '\n';
	chiang.signForm(*form1_ptr);
	cout << *form1_ptr << '\n';
	chiang.executeForm(*form1_ptr);
	return (0);
}