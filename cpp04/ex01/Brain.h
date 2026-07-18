/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:17:36 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 17:19:26 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H
#include <string>

class Brain
{
public:
    Brain();
    Brain(const Brain& other);
    ~Brain();

    Brain&	operator=(const Brain& rhs);

private:
    std::string ideas[100];
};

#endif