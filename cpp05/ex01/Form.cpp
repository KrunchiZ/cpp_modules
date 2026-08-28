/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:00:44 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/28 12:20:54 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

using std::string;
using std::runtime_error;
using std::ostream;
using std::cout;

Form::Form(const string& name, const int& signGrade, const int& execGrade)
	: m_name(name)
	, m_signGrade(signGrade)
	, m_execGrade(execGrade)
	, m_isSigned(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException("Grade too high for " + name);
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException("Grade too low for " + name);
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