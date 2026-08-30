/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:41:16 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 11:47:05 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include <string>

using std::string;

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) {return (*this);}

AForm*  Intern::makeForm(const string& form_name, const string& target)
{
}