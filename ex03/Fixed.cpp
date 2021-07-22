/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:47:46 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/22 14:17:30 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* ************************************************************************** */
/*                                     DATA INIT                              */
/* ************************************************************************** */

const int Fixed::_fixed_point = 8;

/* ************************************************************************** */
/*                           CONSTRUCTOR - DESTRUCTOR                         */
/* ************************************************************************** */

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const int n)
{
	this->_value = n << this->_fixed_point;
}

Fixed::Fixed(const float n)
{
	this->_value = int(roundf(n * (1 << this->_fixed_point)));
}

/* ************************************************************************** */
/*                              OVERLOAD FONCTIONS                            */
/* ************************************************************************** */

Fixed	&Fixed::operator=(const Fixed &right)
{
	this->_value = right.getRawBits();
	return (*this);
}

bool	Fixed::operator==(const Fixed &right) const
{
	return (this->_value == right.getRawBits());
}

bool	Fixed::operator!=(const Fixed &right) const
{
	return (this->_value != right.getRawBits());
}

bool	Fixed::operator<(const Fixed &right) const
{
	return (this->_value < right.getRawBits());
}

bool	Fixed::operator<=(const Fixed &right) const
{
	return (this->_value <= right.getRawBits());
}

bool	Fixed::operator>(const Fixed &right) const
{
	return (this->_value > right.getRawBits());
}

bool	Fixed::operator>=(const Fixed &right) const
{
	return (this->_value >= right.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &right) const
{
	Fixed	temp;

	temp.setRawBits(this->_value + right.getRawBits());
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &right) const
{
	Fixed	temp;

	temp.setRawBits(this->_value - right.getRawBits());
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &right) const
{
	Fixed	temp;

	temp.setRawBits((this->_value * right.getRawBits()) >> this->_fixed_point);
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &right) const
{
	Fixed	temp;

	temp.setRawBits((this->_value << this->_fixed_point) / right.getRawBits());
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->_value--;
	return (temp); 
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->_value++;
	return (temp);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &i)
{
	os << i.toFloat();
	return (os);
}

/* ************************************************************************** */
/*                                MEMBER FONCTIONS                            */
/* ************************************************************************** */

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (double(this->_value) / double(1 << this->_fixed_point));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_fixed_point);
}

/* ************************************************************************** */
/*                                OUTTER FONCTIONS                            */
/* ************************************************************************** */

Fixed	&Fixed::max(Fixed &left, Fixed &right)
{
	return (left > right ? left : right);
}

const Fixed &Fixed::max(Fixed const &left, Fixed const &right)
{
	return (left > right ? left : right);
}

Fixed	&Fixed::min(Fixed &left, Fixed &right)
{
	return (left < right ? left : right);
}

const Fixed &Fixed::min(Fixed const &left, Fixed const &right)
{
	return (left < right ? left : right);
}

Fixed	Fixed::square(const Fixed &n)
{
	return (n * n);
}

Fixed	Fixed::sqrt(const Fixed &n)
{
	return (Fixed(std::sqrt(n.toFloat())));
}
