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

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
