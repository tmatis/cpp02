/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:47:46 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/21 19:32:57 by tmatis           ###   ########.fr       */
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

Fixed::Fixed(const int n)
{
	this->_value = n << this->_fixed_point;
}

Fixed::Fixed(const float n)
{
	this->_value = int(roundf(n * (1 << this->_fixed_point)));
}

Fixed::~Fixed(void) {}

/* ************************************************************************** */
/*                              OVERLOAD FONCTIONS                            */
/* ************************************************************************** */

Fixed	&Fixed::operator=(const Fixed &right)
{
	this->_value = right.getRawBits();
	return (*this);
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
