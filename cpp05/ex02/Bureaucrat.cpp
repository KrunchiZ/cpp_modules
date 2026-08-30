/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 10:45:35 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 12:50:35 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using std::string;
using std::runtime_error;
using std::ostream;
using std::cout;
using std::cerr;

Bureaucrat::GradeTooHighException::GradeTooHighException(const string& str)
	: runtime_error(str) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const string& str)
	: runtime_error(str) {}

Bureaucrat::Bureaucrat(const string& name, int grade)
	: m_name(name), m_grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException("Grade too high for " + name);
	if (grade > 150)
		throw GradeTooLowException("Grade too low for " + name);
	cout << "Bureaucrat " << m_name << "(Grade "
		<< m_grade << ") has joined the office.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: m_name(other.m_name)
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat " << m_name << "(Grade "
		<< m_grade << ") has resigned.\n";
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this == &rhs)
		return (*this);
	m_grade = rhs.m_grade;
	return (*this);
}

const string&	Bureaucrat::getName() const {return (m_name);}
const int&		Bureaucrat::getGrade() const {return (m_grade);}

void	Bureaucrat::incrementGrade()
{
	if (m_grade == 1)
		throw GradeTooHighException("Grade too high for " + m_name);
	--m_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (m_grade == 150)
		throw GradeTooLowException("Grade too low for " + m_name);
	++m_grade;
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		cout << m_name << " signed " << form.getName() << ".\n";
	}
	catch (const AForm::GradeTooLowException&)
	{
		cerr << m_name << " couldn't sign " << form.getName()
			<< " because of insufficient grade.\n";
	}
	catch (const std::runtime_error& ex)
	{
		cerr << m_name << " couldn't sign " << form.getName()
			<< " because " << ex.what() << "\n";
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		cout << m_name << " executed " << form.getName() << ".\n";
	}
	catch (const AForm::GradeTooLowException& ex)
	{
		cerr << m_name << " couldn't execute " << form.getName()
			<< ": " << ex.what() << "\n";
	}
	catch (const std::runtime_error& ex)
	{
		cerr << m_name << " couldn't execute " << form.getName()
			<< ": " << ex.what() << "\n";
	}
}

ostream& operator<<(ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}