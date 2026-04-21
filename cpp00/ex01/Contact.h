/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 01:18:17 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/21 20:13:32 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact
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

	Contact(int id = 0);

	friend void	PhoneBook::setId(int id);
	friend void	PhoneBook::requestUserInput(Info e_info);

private:
	std::string	m_firstName;
	std::string	m_lastName;
	std::string	m_nickname;
	std::string	m_phoneNum;
	std::string	m_darkSecret;
	int			m_id;
};

#endif
