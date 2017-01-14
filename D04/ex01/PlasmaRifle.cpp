#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void)
	: AWeapon("Plasma Rifle", 5, 21) {

}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) : AWeapon(src) { }

PlasmaRifle::~PlasmaRifle(void) {

}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_apcost = rhs._apcost;
		this->_damage = rhs._damage;
	}
	return *this;
}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
