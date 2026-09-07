/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:19:42 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/07 13:29:57 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

struct Data
{
	int			value;
	char		character;
	bool		flag;
	std::string	name;
};

std::ostream&	operator<<(std::ostream& out, const Data& data);

#endif