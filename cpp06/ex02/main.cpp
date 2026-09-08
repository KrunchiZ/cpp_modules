/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:21:17 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/08 17:28:11 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int	main(void)
{
	Base base;
	
	Base* derived = base.generate();
	base.identify(derived);
	base.identify(*derived);
	delete derived;
	return (0);
}