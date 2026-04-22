/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:25:48 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/23 01:06:33 by kchiang          ###   ########.fr       */
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

PhoneBook::PhoneBook()
	: m_currentId(0)
{
}

void	PhoneBook::add()
{
	cout << '\n';
	enterUserInput(m_contacts[m_currentId], firstName);
	enterUserInput(m_contacts[m_currentId], lastName);
	enterUserInput(m_contacts[m_currentId], nickname);
	enterUserInput(m_contacts[m_currentId], phoneNum);
	enterUserInput(m_contacts[m_currentId], darkSecret);
	m_contacts[m_currentId].setId(m_currentId + 1);
	++m_currentId %= 8;
}

void	PhoneBook::search() const
{
	if (m_contacts[0].getId() == 0)
	{
		cout << "\n\t* No Entry Found *\n";
		return ;
	}
	for (string str; str.empty(); )
	{
		for (int i = 0; i < 8 && m_contacts[i].getId(); ++i)
		{
			cout << '\n' << setw(10) << m_contacts[i].getId() << '|'
				<< setw(10) << prep_str(m_contacts[i].getFirstName())
				<< '|' << setw(10) << prep_str(m_contacts[i].getLastName())
				<< '|' << setw(10) << prep_str(m_contacts[i].getNickname())
				<< "\n\n";
		}
		cout << "Please enter Contact Index to display: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			cout << "\n\t* EOF detected. Terminating program. *\n";
			std::exit(EXIT_FAILURE);
		}
		if (is_numeric(str.c_str()))
		{
			std::stringstream ss(str);
			int id = 0;
			ss >> id;
			if (printContact(id))
				break ;
		}
		cout << "\n\t* Invalid Index *";
		str.clear();
	}
}

/* *****************************************************************************
 *  NOTE: Helper functions for PhoneBook::search()
 * */

const string	PhoneBook::prep_str(const string& str) const
{
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + '.');
}

bool	PhoneBook::is_numeric(const char* str) const
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

bool	PhoneBook::printContact(int& id) const
{
	if (id < 0 || id > 7)
		return (false);
	if (m_contacts[id - 1].getId())
	{
		cout << "\n\t" << std::left << setw(20) << "First Name" << ": "
			<< m_contacts[id - 1].getFirstName() << "\n\t" << setw(20)
			<< "Last Name" << ": " << m_contacts[id - 1].getLastName()
			<< "\n\t" << setw(20) << "Nickname" << ": "
			<< m_contacts[id - 1].getNickname() << "\n\t" << setw(20)
			<< "Phone Number" << ": " << m_contacts[id - 1].getPhoneNum()
			<< "\n\t" << setw(20) << "Darkest Secret" << ": "
			<< m_contacts[id - 1].getDarkSecret() << "\n\n" << std::right;
		return (true);
	}
	return (false);
}

/* *****************************************************************************
 *  NOTE: Helper functions for PhoneBook::add()
 * */

void	PhoneBook::enterUserInput(Contact& contact, Info e_info)
{
	string	buffer;
	bool	isNum = true;

	switch (e_info)
	{
		case firstName:
			requestInput(buffer, "first name", !isNum);
			contact.setFirstName(buffer);
			return ;
		case lastName:
			requestInput(buffer, "last name", !isNum);
			contact.setLastName(buffer);
			return ;
		case nickname:
			requestInput(buffer, "nickname", !isNum);
			contact.setNickname(buffer);
			return ;
		case phoneNum:
			requestInput(buffer, "phone number", isNum);
			contact.setPhoneNum(buffer);
			return ;
		case darkSecret:
			requestInput(buffer, "darkest secret", !isNum);
			contact.setDarkSecret(buffer);
			return ;
		default:
			return ;
	}
}

void	PhoneBook::requestInput(string& buffer, const string& str,
			bool isNum) const
{
	while (buffer.empty())
	{
		cout << std::left << setw(30) << "Please enter " + str
			<< ": " << std::right;
		std::getline(std::cin, buffer);
		if (std::cin.eof())
		{
			cout << "\n\t* EOF detected. Terminating program. *\n";
			std::exit(EXIT_FAILURE);
		}
		for (const char* str = buffer.c_str(); *str; ++str)
		{
			if (isNum && (std::isdigit(static_cast<unsigned char>(*str))
					|| *str == '-'))
				continue ;
			if (std::isprint(static_cast<unsigned char>(*str)))
				continue ;
			std::cout << "\t* Invalid Character Detected *\n";
			buffer.clear();
			break ;
		}
	}
}
