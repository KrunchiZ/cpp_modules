/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:23:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/28 00:17:03 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;

namespace
{
bool	argsIsInvalid(int& argc, char* file);
void	parseLine(ifstream& inFile, ofstream& outFile,
			const string& s1, const string& s2);
}

int	main(int argc, char **argv)
{
	if (argsIsInvalid(argc, argv[1]))
		return (1);

	ifstream	inFile(argv[1]);
	ofstream	outFile((string(argv[1]) + ".replace").c_str());

	if (!inFile.is_open() || !outFile.is_open())
	{
		std::cerr << "Error: Failed to open file\n";
		return (1);
	}

	const string	s1(argv[2]);
	const string	s2(argv[3]);

	parseLine(inFile, outFile, s1, s2);
	inFile.close();
	outFile.close();
	return (0);
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
	if (string(file).empty())
	{
		std::cerr << "Error: <infile> cannot be empty string\n";
		return (true);
	}
	return (false);
}

void	parseLine(ifstream& inFile, ofstream& outFile,
			const string& s1, const string& s2)
{
	string	line;

	while (std::getline(inFile, line))
	{
		size_t pos = line.find(s1, 0);
		while (pos != string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
			pos = line.find(s1, pos);
		}
		outFile << line;
		line.clear();
	}
}
}
