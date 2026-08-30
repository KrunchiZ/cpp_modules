/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:00:21 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 11:38:00 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AAForm_HPP
#define AAForm_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
public:
	class GradeTooHighException;
	class GradeTooLowException;
	class InvalidNameException;
	
	AForm(
		const std::string& name = "AForm",
		const int& signGrade = 150,
		const int& execGrade = 150
	);
	AForm(const AForm& other);
	virtual ~AForm();

	AForm&	operator=(const AForm& rhs);
	
	const std::string&	getName() const;
	const int&			getSignGrade() const;
	const int&			getExecGrade() const;
	const bool&			isSigned() const;
	
	void	beSigned(const Bureaucrat& bureaucrat);
	
	virtual void	execute(const Bureaucrat& executor) const = 0;

private:
	const std::string	m_name;
	const int			m_signGrade;
	const int			m_execGrade;
	bool                m_isSigned;
};

class AForm::GradeTooHighException : public std::runtime_error
{
public:
	GradeTooHighException(const std::string& str = "Exceeded highest grade 1");
};

class AForm::GradeTooLowException : public std::runtime_error
{
public:
	GradeTooLowException(const std::string& str = "Exceeded lowest grade 150");
};

class AForm::InvalidNameException : public std::runtime_error
{
public:
	InvalidNameException(const std::string& str = "Invalid form name");
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);


#endif