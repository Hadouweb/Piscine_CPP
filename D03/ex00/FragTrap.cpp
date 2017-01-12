#include "FragTrap.hpp"

FragTrap::FragTrap(std::string pName) : _name(pName) {
	std::cout << "Let's get this party started! (Constructor)" << std::endl;
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 100;
	this->_maxEnergyPoint = 100;
	this->_level = 1;
	this->_meleeAttackDmg = 30;
	this->_rangedAttackDmg = 20;
	this->_armorReduction = 5;
}

FragTrap::FragTrap(void) : _name("Unknown") {
	std::cout << "Let's get this party started! (Constructor Default)" << std::endl;
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 100;
	this->_maxEnergyPoint = 100;
	this->_level = 1;
	this->_meleeAttackDmg = 30;
	this->_rangedAttackDmg = 20;
	this->_armorReduction = 5;
}

FragTrap::FragTrap(FragTrap const &src) {
	std::cout << "Let's get this party started! (Constructor Assignation)" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void) {

}

FragTrap& FragTrap::operator=(FragTrap const &rhs) {
	std::cout << "Let's get this party started! (Constructor Copy)" << std::endl;
	if (this != &rhs)
	{
		 this->_hitPoint = rhs._hitPoint;
		 this->_maxHitPoint = rhs._maxHitPoint;
		 this->_energyPoint = rhs._energyPoint;
		 this->_maxEnergyPoint = rhs._maxEnergyPoint;
		 this->_level = rhs._level;
		 this->_name = rhs._name;
		 this->_meleeAttackDmg = rhs._meleeAttackDmg;
		 this->_rangedAttackDmg = rhs._rangedAttackDmg;
		 this->_armorReduction = rhs._armorReduction;
	}
	return *this;
}

void FragTrap::rangedAttack(const std::string &target) {
	std::cout << "FR4G-TP <" << this->_name << "> attacks <" << target <<
	"> at range, causing <" << this->_rangedAttackDmg << "> points of damage !" << std::endl;
}

void FragTrap::meleeAttack(const std::string &target) {
	std::cout << "FR4G-TP <" << this->_name << "> attacks <" << target <<
	"> at melee, causing <" << this->_meleeAttackDmg << "> points of damage !" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	int reduceDmg = amount - this->_armorReduction;
	if (reduceDmg > 0)
		this->setHitPoint(this->_hitPoint - reduceDmg);
	std::cout << "FR4G-TP <" << this->_name << "> take <" << reduceDmg << "> points of damage !" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FR4G-TP <" << this->_name << "> is repaired <" << amount <<
	"> points of damage !" << std::endl;
	this->setHitPoint(this->_hitPoint + amount);
}

void FragTrap::setHitPoint(int hitPoint) {
	if (hitPoint > this->_maxHitPoint)
		this->_energyPoint = this->_maxHitPoint;
	else if (hitPoint <= 0)
		this->_energyPoint = 0;
	else
		this->_energyPoint = hitPoint;
}

void FragTrap::setEnergyPoint(int energyPoint) {
	if (energyPoint > this->_maxEnergyPoint)
		this->_energyPoint = this->_maxEnergyPoint;
	else if (energyPoint <= 0)
		this->_energyPoint = 0;
	else
		this->_energyPoint = energyPoint;
}

const std::string &FragTrap::getName() const {
	return this->_name;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target) {
	if (this->_energyPoint >= 25) {
		this->setEnergyPoint(this->_energyPoint - 25);
		srand(time(NULL));
		int r = rand() % NB_ATK;
		std::string nameAtk = this->_randAtk[r][0];
		std::string typeAtk = this->_randAtk[r][1];
		std::cout << nameAtk << std::endl;
		if (typeAtk == RANGED_ATK)
			this->rangedAttack(target);
		else
			this->meleeAttack(target);
	} else
		std::cout << "FR4G-TP <" << this->_name << "> is out of energy" << std::endl;
}

const std::string FragTrap::_randAtk[NB_ATK][2] = {
	{"Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!", RANGED_ATK},
	{"Flesh fireworks!", RANGED_ATK},
	{"Freezy peezy!", MELEE_ATK},
	{"Grenaaaade!", RANGED_ATK},
	{"Take that!", MELEE_ATK},
};