/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:47:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/09 01:56:00 by kchiang          ###   ########.fr       */
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
	Contact	m_contacts[8];
	int		m_currentId;
};

#endif
