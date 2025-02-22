#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->raw = 0;
}

Fixed::Fixed(Fixed const & cpy) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &cpy)
		*this = cpy;
}

Fixed & Fixed::operator=(const Fixed & obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->raw = obj.raw;
	return *this;
}

int	Fixed::getRawBits( void ) const {
	return (this->raw);
}

void	Fixed::setRawBits(const int raw) {
	this->raw = raw;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->raw = value << fractionBit;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->raw = roundf(value * (1 << fractionBit));
}

float	Fixed::toFloat() const {
	return (float)raw / (1 << fractionBit);
}

int	Fixed::toInt() const {
	return raw >> fractionBit;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
