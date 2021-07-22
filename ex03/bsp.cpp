/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:00:14 by tmatis            #+#    #+#             */
/*   Updated: 2021/07/22 15:46:07 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*
** is fixed point number in range
*/
bool	in_range(const Fixed &n, const Fixed &min, const Fixed &max)
{
	return (n >= min && n <= max);
}

/*
** triangle point to area
*/
Fixed	triangleArea(Point const &a, Point const &b, Point const &c)
{
	Point	v1 = b - a;
	Point	v2 = c - b;
	Point	v3 = a - c;

	// https://www.mathsisfun.com/geometry/herons-formula.html
	Fixed	s = (v1.length() + v2.length() + v3.length()) / 2;
	return (Fixed::sqrt(s * (s - v1.length()) * (s - v2.length()) * (s - v3.length())));
}

/*
** if(area of PAB+PBC+PAC)==area of ABC) it means the point
** is inside the triangle otherwise its outside the triangle.
*/

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	totalArea = triangleArea(a, b, c); // area of ABC

	Fixed	areaPAB = triangleArea(a, b, point); // area of PAB
	Fixed	areaPBC = triangleArea(b, c, point); // area of PBC
	Fixed	areaPAC = triangleArea(a, c, point); // area of PAC
	
	return (in_range(areaPAB + areaPBC + areaPAC, totalArea - Fixed(0.5f), totalArea + Fixed(0.5f)));	
}
