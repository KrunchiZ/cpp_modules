/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 13:08:12 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/03 18:21:30 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cerrno>

namespace
{
	void str_tolower(std::string& str)
	{
		for (size_t i = 0; i < str.length(); ++i)
		{
			if (std::isupper(str[i]))
			str[i] = std::tolower(str[i]);
		}
	}
	
	bool isChar(const std::string& input)
	{
		return (input.length() == 3 && std::isprint(input[1])
		&& input[0] == '\'' && input[2] == '\'');
	}
	
	bool isInt(const std::string& input)
	{
		for (size_t i = 0; i < input.length(); ++i)
		{
			if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue;
			if (!std::isdigit(input[i]))
				return (false);
			}
			return (true);
		}

	bool isFloat(const std::string& input)
	{
		bool hasDot = false;
		for (size_t i = 0; i < input.length(); ++i)
		{
			if (i == 0 && (input[i] == '-' || input[i] == '+'))
				continue;
			if (input[i] == '.')
			{
				if (hasDot)
					return (false);
				hasDot = true;
				continue;
			}
			if (!std::isdigit(input[i]))
			{
				if (i == input.length() - 1 && input[i] == 'f')
					continue;
				return (false);
			};
		}
		return (true);
	}

	bool isDouble(const std::string& input)
	{
		bool hasDot = false;
		for (size_t i = 0; i < input.length(); ++i)
		{
			if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue;
			if (input[i] == '.')
			{
				if (hasDot)
					return (false);
				hasDot = true;
				continue;
			}
			if (!std::isdigit(input[i]))
				return (false);
		}
		return (true);
	}
	
	bool isSpecialFloat(const std::string& input)
	{
		return (input == "nanf" || input == "+inff" || input == "-inff");
	}

	bool isSpecialDouble(const std::string& input)
	{
		return (input == "nan" || input == "+inf" || input == "-inf");
	}

	void print_char(int ch)
	{
		if (ch < std::numeric_limits<char>::min() || ch > std::numeric_limits<char>::max())
		{
			std::cout << "char: impossible\n";
			return;
		}
		if (std::isprint(ch))
			std::cout << "char: '" << static_cast<char>(ch) << "'\n";
		else
			std::cout << "char: Non displayable\n";
		}
		
	void print_float(float value)
	{
		if (std::isinf(value))
		{
			if (std::signbit(value))
				std::cout << "float: -inff\n";
			else
				std::cout << "float: +inff\n";
		}
		else if (std::isnan(value))
			std::cout << "float: nanf\n";
		else
		{
			if (value == std::floor(value))
				std::cout << "float: " << value << ".0f\n";
			else
				std::cout << "float: " << value << "f\n";
		}
	}

	void print_double(double value)
	{
		if (std::isinf(value))
		{
			if (std::signbit(value))
				std::cout << "double: -inf\n";
			else
				std::cout << "double: +inf\n";
		}
		else if (std::isnan(value))
			std::cout << "double: nan\n";
		else
		{
			if (value == std::floor(value))
				std::cout << "double: " << value << ".0\n";
			else
				std::cout << "double: " << value << "\n";
		}
	}
		
	void print_value(long value)
	{
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		else
		{
			print_char(static_cast<int>(value));
			std::cout << "int: " << static_cast<int>(value) << "\n";
			if (value && std::abs(value) > std::numeric_limits<float>::max())
				std::cout << "float: impossible\n";
			else
				std::cout << "float: " << static_cast<float>(value) << ".0f\n";
			if (value && std::abs(value) > std::numeric_limits<double>::max())
				std::cout << "double: impossible\n";
			else
				std::cout << "double: " << static_cast<double>(value) << ".0\n";
		}
	}

	void print_value(float value)
	{
	}
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {return *this;}

void ScalarConverter::convert(std::string input)
{
	str_tolower(input);
	if (isSpecialFloat(input))
	{
		std::cout << "char: impossible\nint: impossible\n";
		if (input == "nanf")
			print_float(std::numeric_limits<float>::quiet_NaN());
		else if (input == "+inff")
			print_float(std::numeric_limits<float>::infinity());
		else if (input == "-inff")
			print_float(-std::numeric_limits<float>::infinity());
	}
	else if (isSpecialDouble(input))
	{
		std::cout << "char: impossible\nint: impossible\n";
		if (input == "nan")
			print_double(std::numeric_limits<double>::quiet_NaN());
		else if (input == "+inf")
			print_double(std::numeric_limits<double>::infinity());
		else if (input == "-inf")
			print_double(-std::numeric_limits<double>::infinity());
	}
	if (isChar(input))
	{
		char ch = input[1];
		print_char(ch);
		std::cout << "int: " << static_cast<int>(ch) << "\n";
		print_float(static_cast<float>(ch));
		print_double(static_cast<double>(ch));
	}
	if (isInt(input))
	{
		errno = 0;
		long intNum = std::strtol(input.c_str(), NULL, 10);
		if (errno == ERANGE)
			intNum = std::numeric_limits<long>::max();
		print_value(intNum);
	}
}