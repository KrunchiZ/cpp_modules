/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 10:29:55 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/28 11:25:16 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>
#include <string>

class Bureaucrat
{
public:
	class GradeTooHighException;
	class GradeTooLowException;

	Bureaucrat(const std::string& name = "Foo", int grade = 150);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& rhs);

	const std::string&	getName() const;
	const int&			getGrade() const;

	void	incrementGrade();
	void	decrementGrade();
	
private:
	const std::string	m_name;
	int					m_grade;
};

class Bureaucrat::GradeTooHighException : public std::runtime_error
{
public:
	GradeTooHighException(const std::string& str = "Exceeded highest grade 1");
};

class Bureaucrat::GradeTooLowException : public std::runtime_error
{
public:
	GradeTooLowException(const std::string& str = "Exceeded lowest grade 150");
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif