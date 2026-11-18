/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:56:30 by kchiang           #+#    #+#             */
/*   Updated: 2026/11/06 17:52:13 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <stdexcept>

class BitcoinExchange
{
public:
	class InvalidFileException;
	class InvalidDateException;

	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& other);

	void	loadData(const std::string& file);
	void	processInput(const std::string& file);

private:
	std::map<std::string, double> data;
};

class BitcoinExchange::InvalidFileException : public std::runtime_error
{
public:
	InvalidFileException(const std::string& message);
};

class BitcoinExchange::InvalidDateException : public std::runtime_error
{
public:
	InvalidDateException(const std::string& message);
};

#endif