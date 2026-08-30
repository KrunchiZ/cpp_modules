/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:34:46 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 02:58:28 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

using std::string;
using std::cout;
using std::cerr;

PresidentialPardonForm::PresidentialPardonForm(const string& name, const string& target)
try	: AForm(name, 25, 5), m_target(target)
{
	if (getName() != "presidential pardon")
		throw AForm::InvalidNameException();
	cout << "Derived AForm:" << getName() << "(Sign Grade "
		<< getSignGrade() << ", Exec Grade "
		<< getExecGrade() << ") has been created.\n";
}
catch (const AForm::InvalidNameException&)
{
	throw;
}
catch (const std::exception& ex)
{
	cerr << "Form Error: " << ex.what() << "\n";
	throw;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
try	: AForm(other), m_target(other.m_target)
{
	cout << "Derived AForm:" << getName() << "(Sign Grade "
		<< getSignGrade() << ", Exec Grade "
		<< getExecGrade() << ") has been copied.\n";
}
catch (const std::exception& ex)
{
	cerr << "Form Error: " << ex.what() << "\n";
	throw;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "Derived AForm:" << getName() << "(Sign Grade "
		<< getSignGrade() << ", Exec Grade "
		<< getExecGrade() << ") down the paper shredder.\n";
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this == &rhs)
		return (*this);
	AForm::operator=(rhs);
	m_target = rhs.m_target;
	return (*this);
}

const string&	PresidentialPardonForm::getTarget() const {return (m_target);}

void	PresidentialPardonForm::setTarget(const string& new_target) {m_target = new_target;}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	cout << m_target << " has been pardoned by Zaphod Beeblebrox.\n";
}