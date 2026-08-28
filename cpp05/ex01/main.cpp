/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 11:20:23 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/28 15:48:38 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

using std::cout;
using std::cerr;

int main()
{
	{
		Form form("Form_A", 10, 10);
		{
			Bureaucrat chiang("Chiang", 1);	
			cout << chiang << '\n';
			cout << form << '\n';
			chiang.signForm(form);
			cout << form << '\n';
			chiang.signForm(form);
		}
		cout << '\n';
		{
			Bureaucrat donald("Donald", 11);
			Form formB(form);
			cout << donald << '\n';
			cout << formB << '\n';
			donald.signForm(formB);
			cout << "Donald's incrementing his grade.\n";
			donald.incrementGrade();
			cout << donald << '\n';
			donald.signForm(formB);
			cout << formB << '\n';
		}
	}

	cout << '\n';

	try
	{
		Form buildWall("Build_Wall", 151);
		cout << buildWall << '\n';
	}
	catch (const std::exception& ex)
	{
		cerr << "error: " << ex.what() << '\n';
	}
	try
	{
		Form buildWall("Build_Wall", 0);
		cout << buildWall << '\n';
	}
	catch (const std::exception& ex)
	{
		cerr << "error: " << ex.what() << '\n';
	}
	return (0);
}