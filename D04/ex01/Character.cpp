#include "Character.hpp"

Character::Character(std::string const &name)
	: _name(name), _ap(40), _weapon(NULL) {

}

Character::Character(void) { }

Character::Character(Character const &src) {
	*this = src;
}

Character::~Character(void) {

}

Character &Character::operator=(Character const &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_ap = rhs._ap;
	}
	return *this;
}

std::string const Character::getName(void) const {
	return this->_name;
}

int Character::getAp(void) const {
	return this->_ap;
}

const AWeapon* Character::getWeapon(void) const {
	return this->_weapon;
}

void Character::recoverAP(void) {
	this->_ap += 10;
	if (this->_ap > 40)
		this->_ap = 40;
}

void Character::equip(AWeapon *w) {
	this->_weapon = w;
}

void Character::attack(Enemy *e) {
	if (this->_weapon == NULL)
		return ;
	int weponCost = this->_weapon->getAPCost();

	if (this->_ap > 0)
	{
		std::cout << this->_name << " attacks " << e->getType() << " with a "
			<< this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		this->_ap -= weponCost;
		e->takeDamage(this->_weapon->getDamage());
		if (e->getHP() <= 0)
			delete e;
	}
}

std::ostream &operator<<(std::ostream &os, const Character& c) {
	if (c.getWeapon() == NULL)
		os << c.getName() << " has " << c.getAp() << " AP and is unarmed" << std::endl;
	else
		os << c.getName() << " has " << c.getAp() << " AP and wields a " << c.getWeapon()->getName() << std::endl;
	return os;
}
