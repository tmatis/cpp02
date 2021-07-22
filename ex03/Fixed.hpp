/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:53:31 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/22 14:13:59 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fixed_point;
	public:
					Fixed(const Fixed &src);
					Fixed(const int n);
					Fixed(const float n);
					Fixed(void);
					~Fixed();
		bool		operator>(const Fixed &right) const;
		bool		operator<(const Fixed &right) const;
		bool		operator>=(const Fixed &right) const;
		bool		operator<=(const Fixed &right) const;
		bool		operator==(const Fixed &right) const;
		bool		operator!=(const Fixed &right) const;
		Fixed		&operator=(const Fixed &right);
		Fixed		operator+(const Fixed &right) const;
		Fixed		operator-(const Fixed &right) const;
		Fixed		operator*(const Fixed &right) const;
		Fixed		operator/(const Fixed &right) const;
		Fixed		&operator++(void);
		Fixed		&operator--(void);
		Fixed		operator++(int);
		Fixed		operator--(int);
		int			getRawBits(void) const;
		void		setRawBits(const int raw);
		float		toFloat(void) const;
		int			toInt(void) const;
		// static here
		static Fixed		&min (Fixed &left, Fixed &right);
		static const Fixed	&min(const Fixed &left, const Fixed &right);
		static Fixed		&max (Fixed &left, Fixed &right);
		static const Fixed	&max(const Fixed &left, const Fixed &right);
		static Fixed		square(const Fixed &n);
		static Fixed		sqrt(const Fixed &n);

		
};

std::ostream		&operator<<(std::ostream &os, const Fixed &i);

#endif // [FIXED_HPP]
