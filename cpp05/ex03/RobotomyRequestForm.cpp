/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:34:46 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 22:34:25 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <exception>
#include <stdexcept>

using std::string;
using std::cout;
using std::cerr;

RobotomyRequestForm::RobotomyRequestForm(const string& name, const string& target)
try	: AForm(name, 72, 45), m_target(target)
{
	if (getName() != "robotomy request")
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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
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

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "Derived AForm:" << getName() << "(Sign Grade "
		<< getSignGrade() << ", Exec Grade "
		<< getExecGrade() << ") down the paper shredder.\n";
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this == &rhs)
		return (*this);
	AForm::operator=(rhs);
	m_target = rhs.m_target;
	return (*this);
}

const string&	RobotomyRequestForm::getTarget() const {return (m_target);}

void	RobotomyRequestForm::setTarget(const string& new_target) {m_target = new_target;}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	if (std::time(NULL) % 2)
		cout << "*** Drilling noises *** "
			<< m_target << " has been robotomized successfully.\n";
	else
		cout << "Woops! " << m_target << " robotomy failed.\n";
}