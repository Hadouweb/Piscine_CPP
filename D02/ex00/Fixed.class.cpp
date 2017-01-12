#include "Fixed.class.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_fpv = 0;
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fpv;
}

void Fixed::setRawBits(int const raw) {
	this->_fpv = raw;
}

const int Fixed::_fract = 8;