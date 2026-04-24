/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:47:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/24 13:51:50 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <string>

class PhoneBook
{
public:
	enum Info
	{
		firstName,
		lastName,
		nickname,
		phoneNum,
		darkSecret,
	};

	PhoneBook();

	void	add();
	void	search() const;

private:
	void	enterUserInput(Contact& contact, Info e_info);
	void	requestInput(std::string& field, const std::string& str,
				bool isNum) const;
	bool	is_numeric(const char* str) const;
	bool	printContact(int& id) const;

	const std::string	prep_str(const std::string& str) const;

	Contact	m_contacts[8];
	int		m_currentId;
};

#endif
