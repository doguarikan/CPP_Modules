#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	int raw;
	static const int fractionBit = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed(Fixed const &cpy);
		Fixed	&operator=(Fixed const &ıbj);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

} ;

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
