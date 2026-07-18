/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:56:18 by kchiang           #+#    #+#             */
/*   Updated: 2026/07/18 16:55:06 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <string>

class WrongAnimal {

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	virtual ~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal &rhs);

	void makeSound() const;
	virtual const std::string& getType() const;

protected:
	std::string type;
};

#endif