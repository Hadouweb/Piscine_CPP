#include "Pony.hpp"

Pony::Pony(std::string pName) : _name(pName) {
	std::cout << "Constructor called for the pony : " << this->_name << std::endl;
}

Pony::~Pony(void) {
	std::cout << "Destructor called for the pony : " << this->_name << std::endl;
}