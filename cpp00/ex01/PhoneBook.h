/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:47:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/22 22:21:15 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"
# include <string>

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
	void	search();

private:
	void	enterUserInput(Contact& contact, Info e_info);
	void	requestInput(std::string& field, const std::string& str);

	const std::string	prep_str(const std::string& str);
	const bool			is_numeric(const char* str);
	const bool			printContact(int& id);

	Contact	m_contacts[8];
	int		m_currentId;
};

#endif
