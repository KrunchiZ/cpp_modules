/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:28:01 by kchiang           #+#    #+#             */
/*   Updated: 2026/05/05 22:54:15 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();

	Fixed&	operator=(const Fixed& rhs);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	static const int	s_fracBits;
	
	int	m_rawBits;
};
