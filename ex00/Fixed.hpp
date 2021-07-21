#ifndef FIXED_HPP

# define FIXED_HPP

class Fixed
{
	private:
		int					_value;
		static const int	_fixed_point;
	public:
					Fixed(const Fixed &src);
					Fixed(void);
					~Fixed();
		Fixed		&operator=(const Fixed &right);
		int			getRawBits(void) const;
		void		setRawBits(const int raw);
};

#endif // [FIXED_HPP]
