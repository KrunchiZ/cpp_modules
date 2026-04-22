/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 01:18:17 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/22 14:37:55 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

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

	const std::string&	getFirstName();
	const std::string&	getLastName();
	const std::string&	getNickname();
	const std::string&	getPhoneNum();
	const std::string&	getDarkSecret();
	const int&			getId();

private:
	std::string	m_firstName;
	std::string	m_lastName;
	std::string	m_nickname;
	std::string	m_phoneNum;
	std::string	m_darkSecret;
	int			m_id;
};

#endif
