/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 11:20:23 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 03:23:17 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

using std::cout;
using std::cerr;

typedef ShrubberyCreationForm	SForm;
typedef RobotomyRequestForm		RForm;
typedef PresidentialPardonForm	PForm;

int main()
{
	{
		SForm home_shrubbery("Home");
		Bureaucrat chiang("Chiang", 1);	
		cout << chiang << '\n';
		cout << home_shrubbery << '\n';
		chiang.executeForm(home_shrubbery);
		chiang.signForm(home_shrubbery);
		cout << home_shrubbery << '\n';
		chiang.executeForm(home_shrubbery);
	}
	cout << '\n';
	{
		Bureaucrat donald("Donald", 46);
		RForm biden_robotomy("Biden");
		cout << donald << '\n';
		cout << biden_robotomy << '\n';
		donald.signForm(biden_robotomy);
		cout << biden_robotomy << '\n';
		donald.executeForm(biden_robotomy);
		cout << "Donald's incrementing his grade.\n";
		donald.incrementGrade();
		cout << donald << '\n';
		donald.executeForm(biden_robotomy);
	}
	cout << '\n';
	{
		Bureaucrat zaphod("Zaphod", 5);
		PForm trump_pardon("Trump");
		cout << zaphod << '\n';
		cout << trump_pardon << '\n';
		zaphod.signForm(trump_pardon);
		cout << trump_pardon << '\n';
		zaphod.executeForm(trump_pardon);
		cout << "Zaphod decrementing his grade.\n";
		zaphod.decrementGrade();
		cout << zaphod << '\n';
		zaphod.executeForm(trump_pardon);
	}
	return (0);
}