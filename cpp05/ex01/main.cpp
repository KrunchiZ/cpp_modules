/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 11:20:23 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/28 11:49:24 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
	try
	{
		Bureaucrat chiang("Chiang", 1);
		std::cout << chiang << '\n';
		std::cout << "Decrementing grade...\n";
		chiang.decrementGrade();
		std::cout << chiang << '\n';
		std::cout << "Incrementing grade...\n";
		chiang.incrementGrade();
		std::cout << chiang << '\n';
		{
			Bureaucrat alice("Alice", 150);
			std::cout << alice << '\n';
			std::cout << "Alice copies Chiang...\n";
			alice = chiang;
			std::cout << alice << '\n';
		} // Alice goes out of scope here.
		
		// Will throw exception after unwinding the stack, 
		// showing the destructor message.
		std::cout << "Incrementing Chiang's grade. Will throw exception and unwind the stack...\n";
		chiang.incrementGrade();
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Bureaucrat error: " << ex.what() << '\n';
	}
	
	std::cout << '\n';
	try
	{
		Bureaucrat bureaucrat("Donald", 151);
		std::cout << bureaucrat << '\n';
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Bureaucrat error: " << ex.what() << '\n';
	}

	try
	{
		Bureaucrat bureaucrat("Trump", 0);
		std::cout << bureaucrat << '\n';
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Bureaucrat error: " << ex.what() << '\n';
	}
	return (0);
}