/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:25:48 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/21 20:09:57 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "Contact.h"
#include <iostream>

PhoneBook::PhoneBook() : m_currentId(0) {}

void	PhoneBook::add()
{
	requestUserInput(m_contacts[m_currentId], Contact::firstName);
	requestUserInput(m_contacts[m_currentId], Contact::lastName);
	requestUserInput(m_contacts[m_currentId], Contact::nickname);
	requestUserInput(m_contacts[m_currentId], Contact::phoneNum);
	requestUserInput(m_contacts[m_currentId], Contact::darkSecret);
	setId(m_contacts[m_currentId], m_currentId);
	++m_currentId %= 8;
}

void	PhoneBook::search()
{
}

void	PhoneBook::setId(Contact& contact, int id)
{
	contact.m_id = id;
}

void	PhoneBook::requestUserInput(Info e_info)
{
	switch (e_info)
	{
	case firstName:
		requestInfo(contact.m_firstName, "first name");
		return ;
	case lastName:
		requestInfo(contact.m_lastName, "last name");
		return ;
	case nickname:
		requestInfo(contact.m_nickname, "nickname");
		return ;
	case phoneNum:
		requestInfo(contact.m_phoneNum, "phone number");
		return ;
	case darkSecret:
		requestInfo(contact.m_darkSecret, "dark secret");
		return ;
	default:
		return ;
	}
}

void	PhoneBook::requestInfo(std::string& field, const std::string& str)
{
	while (field == "")
	{
		std::cout << "Please enter " << str << " : ";
		std::getline(std::cin, field);
	}
}

