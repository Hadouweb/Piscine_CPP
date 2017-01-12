#include "Fixed.class.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_fpv = 0;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	if (value)
		;
	this->_fpv = value * (1 << Fixed::_fract);
	// Todo
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	if (value)
		;
	this->_fpv = roundf(value * (1 << Fixed::_fract));
	// Todo
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
		this->_fpv = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	return this->_fpv;
}

void Fixed::setRawBits(int const raw) {
	this->_fpv = raw;
}

float Fixed::toFloat(void) const {
	return (float)getRawBits() / (1 << Fixed::_fract);
}

int Fixed::toInt(void) const {
	// Todo
	return getRawBits() / (1 << Fixed::_fract);
}

std::ostream & operator<<(std::ostream & o, Fixed const & f) {
	o << f.toFloat();
	return o;
}

const int Fixed::_fract = 8;