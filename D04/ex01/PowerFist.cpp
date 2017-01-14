#include "PowerFist.hpp"

PowerFist::PowerFist(void)
		: AWeapon("Power Fist", 8, 50) {

}

PowerFist::PowerFist(PowerFist const &src) : AWeapon(src) { }

PowerFist::~PowerFist(void) {

}

PowerFist &PowerFist::operator=(PowerFist const &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_apcost = rhs._apcost;
		this->_damage = rhs._damage;
	}
	return *this;
}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
