/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:00:21 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/28 12:20:55 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Form
{
public:
	class GradeTooHighException;
	class GradeTooLowException;
	
	Form(
		const std::string& name = "Random Form",
		const int& signGrade = 150,
		const int& execGrade = 150
	);
	Form(const Form& other);
	~Form();

	Form&	operator=(const Form& rhs);
	
	const std::string&	getName() const;
	const int&			getSignGrade() const;
	const int&			getExecGrade() const;
	const bool&			isSigned() const;

private:
	const std::string	m_name;
	const int			m_signGrade;
	const int			m_execGrade;
	bool                m_isSigned;
};

class Form::GradeTooHighException : public std::runtime_error
{
public:
	GradeTooHighException(const std::string& str = "Exceeded highest grade 1");
};

class Form::GradeTooLowException : public std::runtime_error
{
public:
	GradeTooLowException(const std::string& str = "Exceeded lowest grade 150");
};

std::ostream& operator<<(std::ostream& out, const Form& Form);


#endif