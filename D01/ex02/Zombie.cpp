#include "Zombie.hpp"

Zombie::Zombie(std::string pType, std::string pName) : _type(pType), _name(pName) {
	std::cout << "- Zombie constructor called" << std::endl;
	this->_announce();
}

Zombie::~Zombie() {
	std::cout << "- Zombie Destructor called" << std::endl;
}

void Zombie::_announce() const {
	std::cout << "<" << this->_name << " (" << this->_type <<
		")> Braiiiiiiinnnssss..." << std::endl;
}