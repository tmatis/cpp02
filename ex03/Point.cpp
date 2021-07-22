#include "Point.hpp"

/* ************************************************************************** */
/*                           CONSTRUCTOR - DESTRUCTOR                         */
/* ************************************************************************** */

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::~Point(void) {}

/* ************************************************************************** */
/*                              OVERLOAD FONCTIONS                            */
/* ************************************************************************** */

Point	&Point::operator=(const Point &right)
{
	this->_x = right._x;
	this->_y = right._y;
	return (*this);
}

Point	Point::operator+(const Point &right) const
{
	Point temp;

	temp.setX(this->getX() + right.getX());
	temp.setY(this->getY() + right.getY());
	return (temp);
}

Point	Point::operator-(const Point &right) const
{
	Point temp;

	temp.setX(this->getX() - right.getX());
	temp.setY(this->getY() - right.getY());
	return (temp);
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
	out << "(" << point.getX() << "; " << point.getY() << ")";
	return (out);
}

/* ************************************************************************** */
/*                                MEMBER FONCTIONS                            */
/* ************************************************************************** */

void	Point::setX(const Fixed x)
{
	this->_x = x;
}

void	Point::setY(const Fixed y)
{
	this->_y = y;
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

Fixed	Point::length(void) const
{
	return (Fixed::sqrt(Fixed::square(this->_x) + Fixed::square(this->_y)));
}
