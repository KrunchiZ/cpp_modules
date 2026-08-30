/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:00:44 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 12:33:36 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::runtime_error;
using std::ostream;
using std::cout;

namespace
{
const string	parse_name(const string& name);
void			strip(string& str);
}

Form::GradeTooHighException::GradeTooHighException(const string& str)
	: runtime_error(str) {}

Form::GradeTooLowException::GradeTooLowException(const string& str)
	: runtime_error(str) {}

Form::Form(const string& name, const int& signGrade, const int& execGrade)
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
		throw runtime_error("Empty form name");
	cout << "Form " << m_name << "(Sign Grade "
		<< m_signGrade << ", Exec Grade "
		<< m_execGrade << ") has been created.\n";
}

Form::Form(const Form& other)
	: m_name(other.m_name)
	, m_signGrade(other.m_signGrade)
	, m_execGrade(other.m_execGrade)
	, m_isSigned(false) {}

Form::~Form()
{
	cout << "Form " << m_name << "(Sign Grade "
		<< m_signGrade << ", Exec Grade "
		<< m_execGrade << ") down the paper shredder.\n";
}

Form&	Form::operator=(const Form& rhs)
{
	if (this == &rhs)
		return (*this);
	m_isSigned = rhs.m_isSigned;
	return (*this);
}

const string&	Form::getName() const {return (m_name);}
const int&		Form::getSignGrade() const {return (m_signGrade);}
const int&		Form::getExecGrade() const {return (m_execGrade);}
const bool&		Form::isSigned() const {return (m_isSigned);}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (m_isSigned)
		throw runtime_error(m_name + " is already signed.");
	if (bureaucrat.getGrade() > m_signGrade)
		throw GradeTooLowException(bureaucrat.getName() + "'s grade is too low.");
	m_isSigned = true;
}

ostream&	operator<<(ostream& out, const Form& form)
{
	out << form.getName() << ", grade to sign: " << form.getSignGrade()
		<< ", grade to execute: " << form.getExecGrade(); 
	if (form.isSigned())
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
	return (result);
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