/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 19:05:27 by kchiang           #+#    #+#             */
/*   Updated: 2026/11/21 23:00:13 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>

int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Could not open file.\n"
			<< "Usage: " << argv[0] << " <input_file>\n";
		return (1);
	}
	
	BitcoinExchange exchange;
	try
	{
		exchange.loadData("data.csv");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}
	
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
		std::cerr << "Error: Failed to open file: " << argv[1] << '\n';

	std::string line;
	if (!std::getline(infile, line) || line != "date | value")
		std::cerr << "Error: Invalid header in file: " << argv[1] << '\n';
	while (std::getline(infile, line))
	{
		try
		{
			exchange.processInput(line);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	if (!infile.eof())
	{
		std::cerr << "Error: Problem reading file: " << argv[1] << '\n';
		return (1);
	}
	return (0);
}