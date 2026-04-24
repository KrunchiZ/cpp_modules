/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 01:18:17 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/24 13:51:36 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
public:
	Contact(int id = 0);

	void	setFirstName(std::string& firstName);
	void	setLastName(std::string& lastName);
	void	setNickname(std::string& nickname);
	void	setPhoneNum(std::string& number);
	void	setDarkSecret(std::string& darkSecret);
	void	setId(int id);

	const std::string&	getFirstName() const;
	const std::string&	getLastName() const;
	const std::string&	getNickname() const;
	const std::string&	getPhoneNum() const;
	const std::string&	getDarkSecret() const;
	const int&			getId() const;

private:
	std::string	m_firstName;
	std::string	m_lastName;
	std::string	m_nickname;
	std::string	m_phoneNum;
	std::string	m_darkSecret;
	int			m_id;
};

#endif
