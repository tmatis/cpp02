#ifndef POINT_HPP

# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;
	public:
						Point(const Point &src);
						Point(void);
						Point(const float x, const float y);
						~Point();
		Fixed			getX(void) const;
		Fixed			getY(void) const;
		void			setX(const Fixed x);
		void			setY(const Fixed x);
		Fixed		length(void) const;
		Point		&operator=(const Point &right);
		Point		operator+(const Point &right) const;
		Point		operator-(const Point &right) const;
};

std::ostream		&operator<<(std::ostream &os, const Point &i);
bool				bsp(Point const a, Point const b, Point const c, Point const point);

#endif // [POINT_HPP]
