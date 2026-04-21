/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:03:10 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/21 17:41:47 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include <iostream>
#include <string>

Contact::Contact(int id) : m_id(id) {}

void	Contact::requestUserInput(Info e_info)
{
	switch (e_info)
	{
	case firstName:
		requestInfo(this->m_firstName, "first name");
		return ;
	case lastName:
		requestInfo(this->m_lastName, "last name");
		return ;
	case nickname:
		requestInfo(this->m_nickname, "nickname");
		return ;
	case phoneNum:
		requestInfo(this->m_phoneNum, "phone number");
		return ;
	case darkSecret:
		requestInfo(this->m_darkSecret, "dark secret");
		return ;
	default:
		return ;
	}
}

void	Contact::requestInfo(std::string& field, const std::string& str)
{
	while (field == "")
	{
		std::cout << "Please enter " << str << " : ";
		std::getline(std::cin, field);
	}
}
