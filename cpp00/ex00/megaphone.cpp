/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:14:11 by kchiang           #+#    #+#             */
/*   Updated: 2026/03/27 12:36:06 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	using std::cout;
	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i(1); i < argc; ++i)
	{
		for (int j(0); argv[i][j]; ++j)
			cout << static_cast<char>(std::toupper(argv[i][j]));
	}
	cout << "\n";
	return (0);
}
