/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:23:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 20:39:11 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

namespace
{
	bool	argsIsInvalid(int& argc, char* file);
}

int	main(int argc, char **argv)
{
	if (argsIsInvalid(argc, argv[1]))
		return (EXIT_FAILURE);

	std::string fileName(argv[1]);
	std::fstream inFile(fileName);
	std::fstream outFile(inFile + ".replace", outFile.out | outFile.trunc);
	if (!inFile.is_open() || !outFile.is_open())
	{
		std::cerr << "Error: Failed to open file\n";
		return ;
	}
	for (std::string line(""); line.empty(); )
	{
	}
}

namespace
{
	bool	argsIsInvalid(int& argc, char* file)
	{
		if (argc != 4)
		{
			std::cerr << "Error: ex04 <infile> <old string> <new string>\n";
			return (true);
		}
		if (std::string(file).empty())
		{
			std::cerr << "Error: <infile> cannot be empty string\n";
			return (true);
		}
		return (false);
	}
}
