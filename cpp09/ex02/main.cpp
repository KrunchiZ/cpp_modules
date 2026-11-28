/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 18:31:06 by kchiang           #+#    #+#             */
/*   Updated: 2026/11/28 20:05:43 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstddef>
#include <sstream>

int	main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error\n";
        return (1);
    }
    
    // MEASURE TIME LAPSE
    std::time_t time_beg = std::time(NULL);
    std::time_t time_end = std::time(NULL);
    // the above method will not be able to measure time lapse in microsecconds

    std::vector<int> vec_array;
    std::deque<int> deq_array;
    for (int i = 1; i < argc; ++i)
    {
        std::stringstream ss(argv[i]);
        int num;
        if (!(ss >> num) || !ss.eof() || num < 0)
        {
            std::cerr << "Error\n";
            return (1);
        }
        vec_array.push_back(num);
        deq_array.push_back(num);
    }
}