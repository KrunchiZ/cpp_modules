/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:18:50 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/11 15:25:11 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	int a = 2;
	int b = 3;
	
	std::cout << "a = " << a << "\nb = " << b << "\n\n-- Swap --\n";
	::swap( a, b );
	std::cout << "a = " << a << "\nb = " << b << '\n';
	std::cout << "min( a, b ) = " << ::min( a, b ) << '\n';
	std::cout << "max( a, b ) = " << ::max( a, b ) << "\n\n";
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << "\nd = " << d << "\n\n-- Swap --\n";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << '\n';
	std::cout << "min( c, d ) = " << ::min( c, d ) << '\n';
	std::cout << "max( c, d ) = " << ::max( c, d ) << '\n';
	return 0;
}