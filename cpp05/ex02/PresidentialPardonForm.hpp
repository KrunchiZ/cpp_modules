/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:31:46 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 03:01:02 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string& target = "default");
	PresidentialPardonForm(const PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);

	const std::string&	getTarget() const;
	void				setTarget(const std::string& new_target);

	virtual void	execute(const Bureaucrat& executor) const;

private:
	std::string	m_target;
};

#endif