#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "- Zombie constructor called" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "- Zombie Destructor called" << std::endl;
}

void Zombie::setType(std::string pType) {
	this->_type = pType;
}

void Zombie::setName(std::string pName) {
	this->_name = pName;
}

void Zombie::announce() const {
	std::cout << "<" << this->_name << " (" << this->_type <<
		")> Braiiiiiiinnnssss..." << std::endl;
}