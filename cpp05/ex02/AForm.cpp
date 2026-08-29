/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:00:44 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/29 14:44:02 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::runtime_error;
using std::ostream;
using std::cout;

AForm::GradeTooHighException::GradeTooHighException(const string& str)
	: runtime_error(str) {}

AForm::GradeTooLowException::GradeTooLowException(const string& str)
	: runtime_error(str) {}

AForm::AForm(const string& name, const int& signGrade, const int& execGrade)
	: m_name(name)
	, m_signGrade(signGrade)
	, m_execGrade(execGrade)
	, m_isSigned(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException("Grade too high for " + name);
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException("Grade too low for " + name);
	cout << "AForm " << m_name << "(Sign Grade "
		<< m_signGrade << ", Exec Grade "
		<< m_execGrade << ") has been created.\n";
}

AForm::AForm(const AForm& other)
	: m_name(other.m_name)
	, m_signGrade(other.m_signGrade)
	, m_execGrade(other.m_execGrade)
	, m_isSigned(false) {}

AForm::~AForm()
{
	cout << m_name << "(Sign Grade "
		<< m_signGrade << ", Exec Grade "
		<< m_execGrade << ") down the paper shredder.\n";
}

AForm&	AForm::operator=(const AForm& rhs)
{
	if (this == &rhs)
		return (*this);
	m_isSigned = rhs.m_isSigned;
	return (*this);
}

const string&	AForm::getName() const {return (m_name);}
const int&		AForm::getSignGrade() const {return (m_signGrade);}
const int&		AForm::getExecGrade() const {return (m_execGrade);}
const bool&		AForm::isSigned() const {return (m_isSigned);}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_signGrade)
		throw GradeTooLowException(bureaucrat.getName() + " is not authorized to sign this form.");
	m_isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!m_isSigned)
		throw runtime_error("Form " + m_name + " is not signed.");
	if (executor.getGrade() > m_execGrade)
		throw GradeTooLowException(executor.getName() + " is not authorized to execute this form.");
}

ostream&	operator<<(ostream& out, const AForm& AForm)
{
	out << AForm.getName() << ", grade to sign: " << AForm.getSignGrade()
		<< ", grade to execute: " << AForm.getExecGrade(); 
	if (AForm.isSigned())
		out << ", signed.";
	else
		out << ", not signed.";
	return (out);
}