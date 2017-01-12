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
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++(void) {
	this->setRawBits(++(this->_fixed));
	return *this;
}

Fixed& Fixed::operator--(void) {
	this->setRawBits(--(this->_fixed));
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

Fixed& Fixed::max(Fixed &lhs, Fixed &rhs) {
	if (lhs.getRawBits() > rhs.getRawBits())
		return lhs;
	return rhs;
}

Fixed& Fixed::min(Fixed &lhs, Fixed &rhs) {
	if (lhs.getRawBits() < rhs.getRawBits())
		return lhs;
	return rhs;
}

const Fixed& Fixed::max(Fixed const &lhs, Fixed const &rhs) {
	if (lhs.toFloat() > rhs.toFloat())
		return lhs;
	return rhs;
}

const Fixed& Fixed::min(Fixed const &lhs, Fixed const &rhs) {
	if (lhs.toFloat() < rhs.toFloat())
		return lhs;
	return rhs;
}

std::ostream & operator<<(std::ostream & o, Fixed const & f) {
	o << f.toFloat();
	return o;
}

const int Fixed::_bits = 8;