/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:25:48 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/22 00:58:48 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "Contact.h"
#include <iostream>
#include <string>

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
	m_contacts[m_currentId].setId(m_currentId);
	++m_currentId %= 8;
}

void	PhoneBook::search()
{
	// TODO: implement a print contact member and call it here.
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
