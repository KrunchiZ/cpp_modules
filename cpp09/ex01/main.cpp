/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 13:39:58 by kchiang           #+#    #+#             */
/*   Updated: 2026/11/28 20:04:57 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid RPN expression\n";
        return (1);
    }

    RPN rpn;
    try
    {
        std::cout << rpn.evaluate(argv[1]) << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return (0);
}