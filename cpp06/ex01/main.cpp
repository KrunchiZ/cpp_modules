/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:26:45 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/07 13:47:14 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
	Data data = {42, 'A', true, "CPP06 ex01"};
	std::cout << "Original Data: " << data << '\n';

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized Data Pointer: " << serialized << '\n';

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Raw Data Pointer: " << *deserialized << '\n';

	return (0);
}