/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:25:48 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/22 14:46:54 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "Contact.h"
#include <iostream>
#include <string>

using std::string;

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

// TODO: implement a print contact member and call it here.
void	PhoneBook::search()
{
	for (string str = ""; str == ""; )
	{
		for (int i = 0; i < 8 && m_contacts[i].getId(); ++i)
		{
			std::cout << std::setw(10) << m_contacts[i].getId() << '|'
				<< std::setw(10) << prep_str(m_contacts[i].getFirstName())
				<< '|' << std::setw(10) << prep_str(m_contacts[i].getLastName())
				<< '|' << std::setw(10) << prep_str(m_contacts[i].getNickname())
				<< '\n';
		}
		std::cout << "Please enter Contact Index to display: ";
		getline(std::cin, str);
	}
}

const string	PhoneBook::prep_str(const string& str)
{
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + '.');
}

void	PhoneBook::enterUserInput(Contact& contact, Info e_info)
{
	std::string	buffer("");

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
			requestInput(buffer, "dark secret");
			contact.setDarkSecret(buffer);
			return ;
		default:
			return ;
	}
}

void	PhoneBook::requestInput(std::string& buffer, const std::string& str)
{
	while (buffer == "")
	{
		std::cout << "Please enter " << str << " : ";
		std::getline(std::cin, buffer);
	}
}
