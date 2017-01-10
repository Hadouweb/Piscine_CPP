#include "HumanA.hpp"

HumanA::HumanA(std::string pName, Weapon pClub) : _name(pName), _club(pClub)  {

}

HumanA::~HumanA(void) {

}

void HumanA::attack(void) const {
	std::cout << this->_name << " attacks whit his " << this->_club.getType();
	std::cout << std::endl;
}