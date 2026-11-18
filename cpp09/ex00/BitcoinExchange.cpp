/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:57:11 by kchiang           #+#    #+#             */
/*   Updated: 2026/11/06 10:57:19 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>

BitcoinExchange::InvalidFileException::InvalidFileException(const std::string& message)
	: std::runtime_error(message) {}

BitcoinExchange::InvalidDateException::InvalidDateException(const std::string& message)
	: std::runtime_error(message) {}

BitcoinExchange::BitcoinExchange() : data() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data) {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);
	data = other.data;
	return (*this);
}

void	BitcoinExchange::loadData(const std::string& file)
{
	std::ifstream infile(file);
	if (!infile.is_open())
		throw InvalidFileException("Failed to open file: " + file);

	std::string line;
	if (!std::getline(infile, line) || line != "date,exchange_rate")
		throw InvalidFileException("Invalid header in file: " + file);
	while (std::getline(infile, line))
	{
		std::stringstream ss(line);
		std::string date;
		double value;
// need to check for comma
		if (!(ss >> date >> value))
			throw InvalidFileException("Invalid line format: " + line);

		data[date] = value;
	}
}