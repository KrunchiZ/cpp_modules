/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:00:44 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 12:38:04 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

using std::string;
using std::runtime_error;
using std::ostream;
using std::cout;

namespace
{
const string	parse_name(const string& name);
void			str_tolower(string& str);
void			strip(string& str);
}

AForm::GradeTooHighException::GradeTooHighException(const string& str)
	: runtime_error(str) {}

AForm::GradeTooLowException::GradeTooLowException(const string& str)
	: runtime_error(str) {}

AForm::InvalidNameException::InvalidNameException(const string& str)
	: runtime_error(str) {}
	
AForm::AForm(const string& name, const int& signGrade, const int& execGrade)
	: m_name(parse_name(name))
	, m_signGrade(signGrade)
	, m_execGrade(execGrade)
	, m_isSigned(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException("Grade too high for " + name);
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException("Grade too low for " + name);
	if (m_name.empty())
		throw InvalidNameException("Empty form name");
	cout << "AForm " << m_name << "(Sign Grade "
		<< m_signGrade << ", Exec Grade "
		<< m_execGrade << ") has been created.\n";
}

AForm::AForm(const AForm& other)
	: m_name(other.m_name)
	, m_signGrade(other.m_signGrade)
	, m_execGrade(other.m_execGrade)
	, m_isSigned(false)
{
	cout << "AForm " << m_name << "(Sign Grade "
		<< m_signGrade << ", Exec Grade "
		<< m_execGrade << ") has been copied.\n";
}

AForm::~AForm()
{
	cout << "AForm " << m_name << "(Sign Grade "
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
	if (m_isSigned)
		throw runtime_error(m_name + " is already signed.");
	if (bureaucrat.getGrade() > m_signGrade)
		throw GradeTooLowException("insufficient grade to sign.");
	m_isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!m_isSigned)
		throw runtime_error(m_name + " is not signed.");
	if (executor.getGrade() > m_execGrade)
		throw GradeTooLowException("insufficient grade to execute.");
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

namespace
{
const string	parse_name(const string& name)
{
	string result(name);
	strip(result);
	str_tolower(result);
	return (result);
}

void	str_tolower(string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
		str[i] = std::tolower(str[i]);
}

void	strip(string& str)
{
	if (str.empty())
		return;
	string::size_type needle;

	needle = str.find_first_not_of(" \t\n\r\f\v");
	if (needle != string::npos)
		str.erase(0, needle);

	needle = str.find_last_not_of(" \t\n\r\f\v");
	if (needle != string::npos)
		str.erase(needle + 1);
}	
}