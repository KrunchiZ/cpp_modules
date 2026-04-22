/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:25:48 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/22 22:25:48 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "Contact.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using std::string;
using std::cout;
using std::setw;

PhoneBook::PhoneBook()
	: m_currentId(0)
{
}

void	PhoneBook::add()
{
	enterUserInput(m_contacts[m_currentId], Contact::firstName);
	enterUserInput(m_contacts[m_currentId], Contact::lastName);
	enterUserInput(m_contacts[m_currentId], Contact::nickname);
	enterUserInput(m_contacts[m_currentId], Contact::phoneNum);
	enterUserInput(m_contacts[m_currentId], Contact::darkSecret);
	m_contacts[m_currentId].setId(m_currentId + 1);
	++m_currentId %= 8;
}

void	PhoneBook::search()
{
	for (int i = 0; i < 8 && m_contacts[i].getId(); ++i)
	{
		cout << setw(10) << m_contacts[i].getId() << '|'
			<< setw(10) << prep_str(m_contacts[i].getFirstName())
			<< '|' << setw(10) << prep_str(m_contacts[i].getLastName())
			<< '|' << setw(10) << prep_str(m_contacts[i].getNickname()) << '\n';
	}
	for (string str = ""; str == ""; )
	{
		cout << "\nPlease enter Contact Index to display: ";
		getline(std::cin, str);
		if (is_numeric(str.c_str()))
		{
			std::stringstream ss(str);
			int id = 0;
			ss >> id;
			if (printContact(id))
				break ;
		}
		cout << "\t* Invalid Index *\n";
		str.clear();
	}
}

/* *****************************************************************************
 *  NOTE: Helper functions for PhoneBook::search()
 * */

const string	PhoneBook::prep_str(const string& str)
{
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + '.');
}

const bool	PhoneBook::is_numeric(const char* str)
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

const bool	PhoneBook::printContact(int& id)
{
	if (id < 0 || id > 7)
		return (false);
	if (m_contacts[id - 1].getId())
	{
		cout << setw(20) << "First Name: " << m_contacts[id - 1].getFirstName()
			<< '\n' << setw(20) << "Last Name: "
			<< m_contacts[id - 1].getLastName() << '\n' << setw(20)
			<< "Nickname: " << m_contacts[id - 1].getNickname() << '\n'
			<< setw(20) << "Phone Number: " << m_contacts[id - 1].getPhoneNum()
			<< '\n' << setw(20) << "Darkest Secret: "
			<< m_contacts[id - 1].getDarkSecret() << '\n\n';
		return (true);
	}
	return (false)
}

/* *****************************************************************************
 *  NOTE: Helper functions for PhoneBook::add()
 * */

void	PhoneBook::enterUserInput(Contact& contact, Info e_info)
{
	string	buffer("");

	switch (e_info)
	{
		case firstName:
			requestInput(buffer, "first name");
			contact.setFirstName(buffer);
			return ;
		case lastName:
			requestInput(buffer, "last name");
			contact.setLastName(buffer);
			return ;
		case nickname:
			requestInput(buffer, "nickname");
			contact.setNickname(buffer);
			return ;
		case phoneNum:
			requestInput(buffer, "phone number");
			contact.setPhoneNum(buffer);
			return ;
		case darkSecret:
			requestInput(buffer, "darkest secret");
			contact.setDarkSecret(buffer);
			return ;
		default:
			return ;
	}
}

void	PhoneBook::requestInput(string& buffer, const string& str)
{
	while (buffer == "")
	{
		std::cout << "Please enter " << str << " : ";
		std::getline(std::cin, buffer);
	}
}
