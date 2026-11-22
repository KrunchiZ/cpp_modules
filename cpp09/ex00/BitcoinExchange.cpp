/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:57:11 by kchiang           #+#    #+#             */
/*   Updated: 2026/11/22 13:43:32 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>

namespace
{
	bool	date_isInvalid(const std::string& date)
	{
		if (date.length() != 10 || date[4] != '-' || date[7] != '-')
			return (true);

		int year, month, day;
		char dash1, dash2;
		std::stringstream ss(date);
		if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-'
			|| dash2 != '-' || !ss.eof())
			return (true);
		if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31
			|| (month == 2 && day > 29) || (month % 2 == 0 && day > 30))
			return (true);
		return (false);
	}
}

BitcoinExchange::BitcoinExchange() : m_data() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: m_data(other.m_data) {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);
	m_data = other.m_data;
	return (*this);
}

void	BitcoinExchange::loadData(const std::string& file)
{
	std::ifstream data_file(file.c_str());
	if (!data_file.is_open())
		throw std::runtime_error("Failed to open file: " + file);

	std::string line;
	if (!std::getline(data_file, line) || line != "date,exchange_rate")
		throw std::runtime_error("Invalid header in file: " + file);
	while (std::getline(data_file, line))
	{
		double value;
		std::string date;
		std::stringstream ss(line);
		if (!(std::getline(ss, date, ',')) || !(ss >> value) || !(ss.eof()))
			throw std::runtime_error("Invalid line in data: " + line);
		m_data[date] = value;
	}
	if (!data_file.eof())
		throw std::runtime_error("Problem reading file: " + file);
}

void	BitcoinExchange::processInput(const std::string& line)
{
	char ch;
	double value;
	std::string date;
	std::stringstream ss(line);

	if (!(ss >> date) || date_isInvalid(date) || !(ss >> ch) || ch != '|'
		|| !(ss >> value) || !(ss.eof()))
		throw std::runtime_error("bad input => " + line);
	if (value < 0)
		throw std::runtime_error("not a positive number.");
	if (value > 1000)
		throw std::runtime_error("too large a number.");

	double exchangeRate = 0.0;
	if (m_data.find(date) == m_data.end())
	{
		std::map<std::string, double>::iterator it;
		it = m_data.lower_bound(date);
		if (it == m_data.begin())
			throw std::runtime_error("no exchange rate available for: " + date);
		--it;
		exchangeRate = it->second;
	}
	else
		exchangeRate = m_data[date];
	std::cout << date << " => " << value << " = " << value * exchangeRate << '\n';
}