#include "Fixed.class.hpp"

Fixed::Fixed(void) {
	this->_fixed = 0;
}

Fixed::Fixed(int const value) {
	this->_fixed = value * (1 << Fixed::_bits);
}

Fixed::Fixed(float const value) {
	this->_fixed = roundf(value * (1 << Fixed::_bits));
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed::~Fixed(void) {
}

Fixed& Fixed::operator=(Fixed const &rhs) {
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
	this->_fixed = raw;
}

float Fixed::toFloat(void) const {
	return (float)getRawBits() / (1 << Fixed::_bits);
}

int Fixed::toInt(void) const {
	return getRawBits() / (1 << Fixed::_bits);
}

bool Fixed::operator>(Fixed const &rhs) {
	if (this->getRawBits() > rhs.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<(Fixed const &rhs) {
	if (this->getRawBits() < rhs.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator>=(Fixed const &rhs) {
	if (this->getRawBits() >= rhs.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<=(Fixed const &rhs) {
	if (this->getRawBits() <= rhs.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator==(Fixed const &rhs) {
	if (this->getRawBits() == rhs.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator!=(Fixed const &rhs) {
	if (this->getRawBits() != rhs.getRawBits())
		return true;
	else
		return false;
}

Fixed Fixed::operator+(Fixed const &rhs) {
	return rhs;
}

Fixed Fixed::operator-(Fixed const &rhs) {
	return rhs;
}

Fixed Fixed::operator*(Fixed const &rhs) {
	return rhs;
}

Fixed Fixed::operator/(Fixed const &rhs) {
	return rhs;
}

Fixed& Fixed::operator++(void) {
	return *this;
}

Fixed& Fixed::operator--(void) {
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed f = *this;
	this->setRawBits(++(this->_fixed));
	return f;
}

Fixed Fixed::operator--(int) {
	Fixed f = *this;
	this->setRawBits(--(this->_fixed));
	return f;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & f) {
	o << f.toFloat();
	return o;
}

const int Fixed::_bits = 8;