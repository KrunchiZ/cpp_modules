/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:56:30 by kchiang           #+#    #+#             */
/*   Updated: 2026/11/21 22:22:07 by kchiang          ###   ########.fr       */
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
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& other);

	void	loadData(const std::string& file);
	void	processInput(const std::string& file);

private:
	std::map<std::string, double> data;
};

#endif