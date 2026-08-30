/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:40:59 by kchiang           #+#    #+#             */
/*   Updated: 2026/08/30 13:23:12 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);

	AForm* makeForm(const std::string& form_name, const std::string& target);
};

#endif