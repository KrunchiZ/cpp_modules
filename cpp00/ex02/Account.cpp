/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 01:42:11 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/24 04:36:12 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts)
	, _amount(initial_deposit)
	, _nbDeposits(0)
	, _nbWithdrawals(0)
{
	++_nbAccounts;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount << ";created" << '\n';
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount << ";closed" << '\n';
}

int	Account::getNbAccounts() {return (_nbAccounts);}
int	Account::getTotalAmount() {return (_totalAmount);}
int	Account::getNbDeposits() {return (_totalNbDeposits);}
int	Account::getNbWithdrawals() {return (_totalNbWithdrawals);}
int	Account::checkAmount() const {return (_amount);}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << '\n';
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";deposits:" << deposit << ";amount:";
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	std::cout << _amount << ";nb_deposits:" << _nbDeposits << '\n';
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused\n";
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	std::cout << withdrawal << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << '\n';
	return (true);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount << ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << '\n';
}

void	Account::_displayTimestamp()
{
	std::time_t	currentTime = std::time(NULL);
	char		buffer[19];

	if (std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ",
		std::localtime(&currentTime)))
		std::cout << buffer;
}
