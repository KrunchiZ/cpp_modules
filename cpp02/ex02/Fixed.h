/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:28:01 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/06 01:07:07 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& other);
	~Fixed();

	Fixed&	operator=(const Fixed& rhs);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	static const int	s_fracBits;
	
	int	m_rawBits;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);
