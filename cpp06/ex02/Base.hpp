/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:48:54 by kchiang           #+#    #+#             */
/*   Updated: 2026/09/08 15:02:01 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
	Base();
	Base(const Base&);
	virtual ~Base();

	Base*	generate(void);
	void	identify(Base* p);
	void	identify(Base& p);
};

#endif