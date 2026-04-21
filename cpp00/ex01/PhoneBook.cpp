/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:25:48 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/21 18:40:20 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "Contact.h"
#include <iostream>

PhoneBook::PhoneBook() : m_currentId(0) {}

void	PhoneBook::add()
{
	m_contacts[m_currentId].requestUserInput(Contact::firstName);
	m_contacts[m_currentId].requestUserInput(Contact::lastName);
	m_contacts[m_currentId].requestUserInput(Contact::nickname);
	m_contacts[m_currentId].requestUserInput(Contact::phoneNum);
	m_contacts[m_currentId].requestUserInput(Contact::darkSecret);
	++m_currentId %= 8;
}

void	PhoneBook::search()
{
}
