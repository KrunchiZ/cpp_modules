/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:31:18 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/07 13:45:34 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

std::ostream&	operator<<(std::ostream& out, const Data& data)
{
	out << std::boolalpha
		<< "{\n\tvalue: " << data.value
		<< ",\n\tcharacter: '" << data.character
		<< "',\n\tflag: " << data.flag
		<< ",\n\tname: \"" << data.name << "\"\n}"
		<< std::noboolalpha;
	return (out);
}