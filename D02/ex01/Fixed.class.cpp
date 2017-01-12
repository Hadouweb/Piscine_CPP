#include "Fixed.class.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = value * (1 << Fixed::_bits);
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(value * (1 << Fixed::_bits));
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &rhs) {
	std::cout << "Assignation operator called" << std::endl;
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

std::ostream & operator<<(std::ostream & o, Fixed const & f) {
	o << f.toFloat();
	return o;
}

const int Fixed::_bits = 8;