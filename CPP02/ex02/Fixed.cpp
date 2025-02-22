#include "Fixed.hpp"

Fixed::Fixed() {
	this->raw = 0;
}

Fixed::Fixed(Fixed const & copy) {
	if (this != &copy)
		*this = copy;
}

Fixed & Fixed::operator=(const Fixed & other) {
	if (this != &other)
		this->raw = other.raw;
	return *this;
}

int	Fixed::getRawBits() const {
	return (this->raw);
}

void	Fixed::setRawBits(const int raw) {
	this->raw = raw;
}

Fixed::~Fixed() {
}

Fixed::Fixed(const int value) {
	this->raw = value << fractionBit;
}

Fixed::Fixed(const float value) {
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

bool Fixed::operator>(const Fixed& fixed) const {
	return this->raw > fixed.raw;
}

bool Fixed::operator<(const Fixed& fixed) const {
	return this->raw < fixed.raw;
}

bool Fixed::operator>=(const Fixed& fixed) const {
	return this->raw >= fixed.raw;
}

bool Fixed::operator<=(const Fixed& fixed) const {
	return this->raw <= fixed.raw;
}

bool Fixed::operator==(const Fixed& fixed) const {
	return this->raw == fixed.raw;
}

bool Fixed::operator!=(const Fixed& fixed) const {
	return this->raw != fixed.raw;
}

Fixed Fixed::operator+(const Fixed& fixed) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const {
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++() {
	this->raw++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->raw++;
	return temp;
}

Fixed& Fixed::operator--() {
	this->raw--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->raw--;
	return temp;
}

Fixed&	Fixed::min(Fixed &a, Fixed &b) {
	if (a.raw < b.raw)
		return a;
	return b;
}
const Fixed	&Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.raw < b.raw)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b) {
	if (a.raw > b.raw)
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.raw > b.raw)
		return a;
	return b;
}
