#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	int raw;
	static const int fractionBit = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &cpy);
		Fixed &operator=(const Fixed &obj);
		int getRawBits() const;
		void setRawBits(int const raw);

} ;

#endif
