/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:31:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 03:13:08 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <string>
#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;

int	main(void)
{
	PhoneBook	phoneBook;
	string		cmdInput;

	while (true)
	{
		cout << "Please enter command [ADD / SEARCH / EXIT]: ";
		std::getline(std::cin, cmdInput);
		if (std::cin.eof())
		{
			cout << "\n\t* EOF detected. Terminating program. *\n";
			std::exit(EXIT_FAILURE);
		}
		if (cmdInput == "ADD")
			phoneBook.add();
		else if (cmdInput == "SEARCH")
			phoneBook.search();
		else if (cmdInput == "EXIT")
			break ;
		cmdInput.clear();
		if (std::cin.eof())
		{
			cout << "\n\t* EOF detected. Terminating program. *\n";
			break ;
		}
	}
	return (EXIT_SUCCESS);
}
