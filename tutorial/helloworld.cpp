/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helloworld.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:31:34 by kchiang           #+#    #+#             */
/*   Updated: 2026/03/12 15:03:44 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// copy initializer using =
// direct initializer using ()
// list initializer using {} (similar to compound initializer but without the '=' )
// copy-list initializer using = {} similar to compound initializer
int	main(void)
{
	int			nb = 42;
	std::string	str ("Hello world!");

	std::cout << nb << str;
	return (0);
}
