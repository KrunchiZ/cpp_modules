/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 13:08:12 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/04 18:25:12 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cerrno>

namespace
{
	void	str_tolower(std::string& str);
	bool	isChar(const std::string& input);
	bool	isInt(const std::string& input);
	bool	isFloat(const std::string& input);
	bool	isDouble(const std::string& input);
	bool	isSpecial(const std::string& input);
	void	process_char(const std::string& input);
	void	process_int(const std::string& input);
	void	process_float(const std::string& input);
	void	process_double(const std::string& input);
	void	process_special(const std::string& input);
	void	print_char(int ch);	
	void	print_float(double value, int precision = 1);
	void	print_double(long double value, int precision = 1);	
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {return *this;}

void ScalarConverter::convert(std::string input)
{
	str_tolower(input);
	if (isSpecial(input))
		process_special(input);
	else if (isChar(input))
		process_char(input);
	else if (isInt(input))
		process_int(input);
	else if (isFloat(input))
		process_float(input);
	else if (isDouble(input))
		process_double(input);
	else
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

namespace
{
	void	str_tolower(std::string& str)
	{
		for (size_t i = 0; i < str.length(); ++i)
		{
			if (std::isupper(str[i]))
			str[i] = std::tolower(str[i]);
		}
	}
	
	bool	isChar(const std::string& input)
	{
		return (input.length() == 3 && std::isprint(input[1])
		&& input[0] == '\'' && input[2] == '\'');
	}
	
	bool	isInt(const std::string& input)
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

	bool	isFloat(const std::string& input)
	{
		bool hasDot = false;
		if (input[input.length() - 1] != 'f')
			return (false);
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

	bool	isDouble(const std::string& input)
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
	
	bool	isSpecial(const std::string& input)
	{
		return (input == "nanf" || input == "+inff" || input == "-inff"
			|| input == "nan" || input == "+inf" || input == "-inf");
	}

	void	process_char(const std::string& input)
	{
		char ch = input[1];
		print_char(ch);
		std::cout << "int: " << static_cast<int>(ch) << "\n";
		print_float(static_cast<float>(ch));
		print_double(static_cast<double>(ch));
	}
		
	void	process_int(const std::string& input)
	{
		errno = 0;
		long intNum = std::strtol(input.c_str(), NULL, 10);
		if (errno == ERANGE
			|| (intNum < std::numeric_limits<int>::min() || intNum > std::numeric_limits<int>::max()))
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		else
		{
			print_char(static_cast<int>(intNum));
			std::cout << "int: " << static_cast<int>(intNum) << "\n";
			print_float(static_cast<double>(intNum));
			print_double(static_cast<long double>(intNum));
		}
	}

	void	process_float(const std::string& input)
	{
		errno = 0;
		double floatNum = std::strtod(input.c_str(), NULL);
		if (errno == ERANGE
			|| (floatNum && std::abs(floatNum) > std::numeric_limits<float>::max()))
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		else
		{
			int precision = 1;
			if (input.find('.') != std::string::npos)
			{
				size_t dot_pos = input.find('.');
				size_t f_pos = input.find('f');
				precision = f_pos - dot_pos - 1;
			}
			print_char(static_cast<int>(floatNum));
			if (floatNum < std::numeric_limits<int>::min() || floatNum > std::numeric_limits<int>::max())
				std::cout << "int: impossible\n";
			else
				std::cout << "int: " << static_cast<int>(floatNum) << "\n";
			print_float(floatNum, precision);
			print_double(static_cast<long double>(floatNum), precision);
		}
	}

	void	process_double(const std::string& input)
	{
		errno = 0;
		long double doubleNum = std::strtold(input.c_str(), NULL);
		if (errno == ERANGE
			|| (doubleNum && std::abs(doubleNum) > std::numeric_limits<double>::max()))
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		else
		{
			int precision = 1;
			if (input.find('.') != std::string::npos)
			{
				size_t dot_pos = input.find('.');
				precision = input.length() - dot_pos - 1;
			}
			print_char(static_cast<int>(doubleNum));
			if (doubleNum < std::numeric_limits<int>::min() || doubleNum > std::numeric_limits<int>::max())
				std::cout << "int: impossible\n";
			else
				std::cout << "int: " << static_cast<int>(doubleNum) << "\n";
			print_float(static_cast<double>(doubleNum), precision);
			print_double(doubleNum, precision);
		}
	}

	void	process_special(const std::string& input)
	{
		if (input == "nanf" || input == "nan")
		{
			std::cout << "char: impossible\nint: impossible\n";
			print_float(std::numeric_limits<float>::quiet_NaN());
			print_double(std::numeric_limits<double>::quiet_NaN());
		}
		else if (input == "+inff" || input == "+inf")
		{
			std::cout << "char: impossible\nint: impossible\n";
			print_float(std::numeric_limits<float>::infinity());
			print_double(std::numeric_limits<double>::infinity());
		}
		else if (input == "-inff" || input == "-inf")
		{
			std::cout << "char: impossible\nint: impossible\n";
			print_float(-std::numeric_limits<float>::infinity());
			print_double(-std::numeric_limits<double>::infinity());
		}
	}

	void	print_char(int ch)
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
		
	void	print_float(double value, int precision)
	{
		std::cout << std::fixed << std::setprecision(precision);
		if (value && std::abs(value) > std::numeric_limits<float>::max()
			&& !std::isinf(value))
		{
			std::cout << "float: impossible\n";
			return;
		}
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
			std::cout << "float: " << static_cast<float>(value) << "f\n";
		std::cout.unsetf(std::ios::floatfield);
	}

	void	print_double(long double value, int precision)
	{
		std::cout << std::fixed << std::setprecision(precision);
		if (value && std::abs(value) > std::numeric_limits<double>::max()
			&& !std::isinf(value))
		{
			std::cout << "double: impossible\n";
			return;
		}
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
			std::cout << "double: " << static_cast<double>(value) << "\n";
		std::cout.unsetf(std::ios::floatfield);
	}
}