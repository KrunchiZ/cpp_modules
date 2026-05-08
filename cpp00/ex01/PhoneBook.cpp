/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:25:48 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/09 01:56:23 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "Contact.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>

using std::string;
using std::cout;
using std::setw;

namespace
{
	bool			enterUserInput(Contact& contact, PhoneBook::Info e_info);
	bool			requestInput(string& field, const string& str, bool isNum);
	bool			is_numeric(const char* str);
	bool			printContact(const Contact& contact, int& id);
	const string	prep_str(const string& str);
}

PhoneBook::PhoneBook()
	: m_currentId(0)
{
}

void	PhoneBook::add()
{
	cout << "\nWriting to Index #" << m_currentId + 1 << '\n';
	if (!enterUserInput(m_contacts[m_currentId], firstName)
		|| !enterUserInput(m_contacts[m_currentId], lastName)
		|| !enterUserInput(m_contacts[m_currentId], nickname)
		|| !enterUserInput(m_contacts[m_currentId], phoneNum)
		|| !enterUserInput(m_contacts[m_currentId], darkSecret))
		return ;
	m_contacts[m_currentId].setId(m_currentId + 1);
	++m_currentId %= 8;
	cout << '\n';
}

void	PhoneBook::search() const
{
	if (m_contacts[0].getId() == 0)
	{
		cout << "\n\t* No Entry Found *\n\n";
		return ;
	}
	for (string str; str.empty(); )
	{
		cout << '\n' << setw(10) << "Index" << '|' << setw(10) << "First Name"
			<< '|' << setw(10) << "Last Name" << '|' << setw(10) << "Nickname"
			<< '\n' << "--------------------------------------------\n";
		for (int i = 0; i < 8 && m_contacts[i].getId(); ++i)
		{
			cout << setw(10) << m_contacts[i].getId() << '|'
				<< setw(10) << prep_str(m_contacts[i].getFirstName())
				<< '|' << setw(10) << prep_str(m_contacts[i].getLastName())
				<< '|' << setw(10) << prep_str(m_contacts[i].getNickname())
				<< '\n';
		}
		cout << "\nPlease enter Contact Index to display ([0]->Main Menu): ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return ;
		if (is_numeric(str.c_str()))
		{
			std::stringstream ss(str);
			int id = 0;
			ss >> id;
			if (printContact(m_contacts[id - 1], id))
				break ;
		}
		cout << "\n\t* Invalid Index *\n";
		str.clear();
	}
}

namespace
{
/* *****************************************************************************
 *  NOTE: Helper functions for PhoneBook::search()
 * */

const string	prep_str(const string& str)
{
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + '.');
}

bool	is_numeric(const char* str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
	{
		if (!std::isdigit(static_cast<unsigned char>(*str++)))
			return (false);
	}
	return (true);
}

bool	printContact(const Contact& contact, int& id)
{
	if (!id)
		return (true);
	if (id < 1 || id > 8)
		return (false);
	if (contact.getId())
	{
		cout << "\n\t" << std::left << setw(20) << "First Name" << ": "
			<< contact.getFirstName() << "\n\t" << setw(20) << "Last Name"
			<< ": " << contact.getLastName() << "\n\t" << setw(20) << "Nickname"
			<< ": " << contact.getNickname() << "\n\t" << setw(20)
			<< "Phone Number" << ": " << contact.getPhoneNum() << "\n\t"
			<< setw(20) << "Darkest Secret" << ": " << contact.getDarkSecret()
			<< "\n\n" << std::right;
		return (true);
	}
	return (false);
}

/* *****************************************************************************
 *  NOTE: Helper functions for PhoneBook::add()
 * */

bool	enterUserInput(Contact& contact, PhoneBook::Info e_info)
{
	string	buffer;
	bool	inputRequested = true;
	bool	isNum = true;

	switch (e_info)
	{
		case PhoneBook::firstName:
			inputRequested = requestInput(buffer, "first name", !isNum);
			contact.setFirstName(buffer);
			return (inputRequested);
		case PhoneBook::lastName:
			inputRequested = requestInput(buffer, "last name", !isNum);
			contact.setLastName(buffer);
			return (inputRequested);
		case PhoneBook::nickname:
			inputRequested = requestInput(buffer, "nickname", !isNum);
			contact.setNickname(buffer);
			return (inputRequested);
		case PhoneBook::phoneNum:
			inputRequested = requestInput(buffer, "phone number", isNum);
			contact.setPhoneNum(buffer);
			return (inputRequested);
		case PhoneBook::darkSecret:
			inputRequested = requestInput(buffer, "darkest secret", !isNum);
			contact.setDarkSecret(buffer);
			return (inputRequested);
		default:
			return (inputRequested);
	}
}

bool	requestInput(string& buffer, const string& str, bool isNum)
{
	while (buffer.empty())
	{
		cout << std::left << setw(30) << "\tPlease enter " + str
			<< ": " << std::right;
		std::getline(std::cin, buffer);
		if (std::cin.eof())
			return (false);
		if (buffer.empty())
			cout << "\t* No Empty Field *\n";
		const char* str = buffer.c_str();
		for (int i = 0; str[i]; ++i)
		{
			if ((isNum && i == 0 && str[i] == '+')
				|| (!isNum && std::isprint(static_cast<unsigned char>(str[i])))
				|| (isNum && (std::isdigit(static_cast<unsigned char>(str[i]))
					|| str[i] == '-')))
				continue ;
			std::cout << "\t* Invalid Character Detected *\n";
			buffer.clear();
			break ;
		}
	}
	return (true);
}
}
