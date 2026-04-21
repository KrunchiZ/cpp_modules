/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:47:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/21 20:12:08 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class PhoneBook
{
public:
	PhoneBook();

	void	add();
	void	search();

private:
	void	requestUserInput(Info e_info);
	void	requestInfo(std::string& field, const std::string& str);
	void	setId(Contact& contact, int id);

	Contact	m_contacts[8];
	int		m_currentId;
};

#endif
