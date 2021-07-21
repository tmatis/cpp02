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
		Fixed		&operator=(const Fixed &right);
		int			getRawBits(void) const;
		void		setRawBits(const int raw);
		float		toFloat(void) const;
		int			toInt(void) const;
};

std::ostream		&operator<<(std::ostream &os, const Fixed &i);

#endif // [FIXED_HPP]
