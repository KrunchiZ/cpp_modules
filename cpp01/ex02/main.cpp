/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:43:40 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/27 13:03:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

int	main(void)
{
	std::string		str("HI THIS IS BRAIN");
	std::string*	stringPTR(&str);
	std::string&	stringREF(str);

	using std::cout;
	using std::setw;
	cout << '\n';
	cout << setw(30) << "Memory address of str = " << &str << '\n';
	cout << setw(30) << "Memory address of stringPTR = " << &stringPTR << '\n';
	cout << setw(30) << "Memory address of stringREF = " << &stringREF << '\n';
	cout << '\n';
	cout << setw(30) << "Value of str = " << str << '\n';
	cout << setw(30) << "Value of stringPTR = " << stringPTR << '\n';
	cout << setw(30) << "Value of stringREF = " << stringREF << '\n';
	cout << '\n';
	return (0);
}
