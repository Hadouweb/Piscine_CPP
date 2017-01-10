#include "HumanB.hpp"

HumanB::HumanB(std::string pName) : _name(pName) {

}

HumanB::~HumanB(void) {

}

void HumanB::setWeapon(Weapon pClub) {
	this->_club = &pClub;
}

void HumanB::attack(void) const {
	std::cout << this->_name << " attacks whit his " << this->_club->getType();
	std::cout << std::endl;
}