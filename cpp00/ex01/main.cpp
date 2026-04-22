/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:31:02 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/22 23:04:34 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <string>
#include <iostream>

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
		if (cmdInput == "ADD")
			phoneBook.add();
		else if (cmdInput == "SEARCH")
			phoneBook.search();
		else if (cmdInput == "EXIT")
			break ;
		cmdInput.clear();
	}
	return (0);
}
