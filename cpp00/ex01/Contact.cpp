/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:03:10 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/22 14:34:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include <iostream>
#include <string>

using std::string;

Contact::Contact(int id)
	: m_id(id)
{
}

void	Contact::setFirstName(string& firstName) {m_firstName = firstName;}
void	Contact::setLastName(string& lastName) {m_lastName = lastName;}
void	Contact::setNickname(string& nickname) {m_nickname = nickname;}
void	Contact::setPhoneNum(string& phoneNum) {m_phoneNum = phoneNum;}
void	Contact::setDarkSecret(string& darkSecret) {m_darkSecret = darkSecret;}
void	Contact::setId(int id) {m_id = id;}

const string&	Contact::getFirstName() {return (m_firstName);}
const string&	Contact::getLastName() {return (m_lastName);}
const string&	Contact::getNickname() {return (m_nickame);}
const string&	Contact::getPhoneNum() {return (m_phoneNum);}
const string&	Contact::getDarkSecret() {return (m_darkSecret);}
const int&		Contact::getId() {return (m_id);}
