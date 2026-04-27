/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 01:34:11 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/28 02:27:16 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: ./harlFilter [<DEBUG>/<INFO>/<WARNING>/<ERROR>]\n";
		return (1);
	}

	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}
