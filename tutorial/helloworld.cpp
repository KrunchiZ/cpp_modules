/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helloworld.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:31:34 by kchiang           #+#    #+#             */
/*   Updated: 2026/03/18 16:29:44 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

// copy initializer using =
// direct initializer using ()
// list initializer using {} (similar to compound initializer but without the '=' )
// copy-list initializer using = {} similar to compound initializer
int	main(void)
{
	int	a;
	int	b;
	int	c;

	std::cout << "Enter three numbers: ";
	std::cin >> a >> b >> c;
	std::cout << "You entered " << a << ", " << b << ", and " << c << ".\n";
	return (EXIT_SUCCESS);
}
