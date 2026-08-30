/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:34:46 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 03:28:27 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>

using std::string;
using std::cout;

ShrubberyCreationForm::ShrubberyCreationForm(const string& target)
try	: AForm("ShrubberyCreationForm", 145, 137), m_target(target)
{
	cout << "Derived AForm:" << getName() << "(Sign Grade "
		<< getSignGrade() << ", Exec Grade "
		<< getExecGrade() << ") has been created.\n";
}
catch (const std::exception& ex)
{
	cout << "Form Error: " << ex.what() << "\n";
	throw;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
try	: AForm(other), m_target(other.m_target)
{
	cout << "Derived AForm:" << getName() << "(Sign Grade "
		<< getSignGrade() << ", Exec Grade "
		<< getExecGrade() << ") has been copied.\n";
}
catch (const std::exception& ex)
{
	cout << "Form Error: " << ex.what() << "\n";
	throw;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "Derived AForm:" << getName() << "(Sign Grade "
		<< getSignGrade() << ", Exec Grade "
		<< getExecGrade() << ") down the paper shredder.\n";
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this == &rhs)
		return (*this);
	AForm::operator=(rhs);
	m_target = rhs.m_target;
	return (*this);
}

const string&	ShrubberyCreationForm::getTarget() const {return (m_target);}

void	ShrubberyCreationForm::setTarget(const string& new_target) {m_target = new_target;}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	std::ofstream outfile((m_target + "_shrubbery").c_str());
	if (!outfile.is_open())
		throw std::runtime_error("Failed to open file: "
			+ m_target + "_shrubbery");
	
	outfile
		<< "       { ^ }\n"
		<< "    {    o    }\n"
		<< "  {             }\n"
		<< " {   o        o  }\n"
		<< "  {  _- o   -_  }\n"
		<< "    ~  \\\\ //  ~\n"
		<< " _- -   | | _- _\n"
		<< "   _ -  | |   -_\n"
		<< " ______// \\\\______\n";

	if (!outfile.good())
		throw std::runtime_error("I/O error while writing to "
			+ m_target + "_shrubbery");
	outfile.close();
}