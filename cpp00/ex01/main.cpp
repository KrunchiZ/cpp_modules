/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:31:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/23 00:46:20 by kchiang          ###   ########.fr       */
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
	}
	return (EXIT_SUCCESS);
}
