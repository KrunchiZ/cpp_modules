/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 11:20:23 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/28 11:24:44 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	try
	{
		{
			Bureaucrat bureaucrat("Chiang", 1);
			std::cout << bureaucrat << '\n';
		}
		// This will throw an exception
		Bureaucrat bureaucrat("Doe", 0);
		std::cout << bureaucrat << '\n';
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << '\n';
	}
	return (0);
}