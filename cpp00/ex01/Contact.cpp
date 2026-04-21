/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:03:10 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/21 16:30:19 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.h"

Contact::Contact(int id) : m_id(id) {}

void	Contact::getUserInput(Info e_info)
{
	switch (e_info)
	{
	case firstName:
		getInfo(this->m_firstName, "first name");
		return ;
	case lastName:
		getInfo(this->m_lastName, "last name");
		return ;
	case nickname:
		getInfo(this->m_nickname, "nickname");
		return ;
	case phoneNum:
		getInfo(this->m_phoneNum, "phone number");
		return ;
	case darkSecret:
		getInfo(this->m_darkSecret, "dark secret");
		return ;
	default:
		return ;
	}
}

void	Contact::getInfo(std::string& field, const std::string& str)
{
	while (field == "")
	{
		std::cout << "Please enter " << str << " : ";
		std::getline(std::cin, field);
	}
}
