/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helloworld.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:31:34 by kchiang           #+#    #+#             */
/*   Updated: 2026/04/22 14:05:31 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>

// copy initializer using =
// direct initializer using ()
// list initializer using {} (similar to compound initializer but without the '=' )
// copy-list initializer using = {} similar to compound initializer
int	main(void)
{
	std::cout << std::setw(10)
		<< std::string("Enter three numbers").substr(0, 9) + "." << "\n";
	return (EXIT_SUCCESS);
}
