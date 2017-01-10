#include "Weapon.hpp"

Weapon::Weapon(std::string pType) : _type(pType) {

}

Weapon::~Weapon(void) {

}

const std::string & Weapon::getType() const {
	return this->_type;
}

void Weapon::setType(std::string pType) {
	this->_type = pType;
}