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
	std::cout << "FR4G-TP <" << this->_name << "> take <" << amount << "> points of damage !" << std::endl;
	int reduceDmg = amount - this->_armorReduction;
	if (reduceDmg > 0)
		this->setHitPoint(this->_hitPoint - reduceDmg);
}

void FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FR4G-TP <" << this->_name << "> is repaired <" << amount <<
	"> points of damage !" << std::endl;
}

int FragTrap::getHitPoint() const {
	return this->_hitPoint;
}

void FragTrap::setHitPoint(int hitPoint) {
	if (hitPoint > this->_maxHitPoint)
		this->_energyPoint = this->_maxHitPoint;
	else if (hitPoint <= 0)
		this->_energyPoint = 0;
	else
		this->_energyPoint = hitPoint;
}

int FragTrap::getMaxHitPoint() const {
	return this->_maxHitPoint;
}

void FragTrap::setMaxHitPoint(int maxHitPoint) {
	this->_maxHitPoint = maxHitPoint;
}

int FragTrap::getEnergyPoint() const {
	return this->_energyPoint;
}

void FragTrap::setEnergyPoint(int energyPoint) {
	if (energyPoint > this->_maxEnergyPoint)
		this->_energyPoint = this->_maxEnergyPoint;
	else if (energyPoint <= 0)
		this->_energyPoint = 0;
	else
		this->_energyPoint = energyPoint;
}

int FragTrap::getMaxEnergyPoint() const {
	return this->_maxEnergyPoint;
}

void FragTrap::setMaxEnergyPoint(int maxEnergyPoint) {
	this->_maxEnergyPoint = maxEnergyPoint;
}

int FragTrap::getLevel() const {
	return this->_level;
}

void FragTrap::setLevel(int level) {
	this->_level = level;
}

const std::string &FragTrap::getName() const {
	return this->_name;
}

void FragTrap::setName(const std::string &name) {
	this->_name = name;
}

int FragTrap::getMeleeAttackDmg() const {
	return this->_meleeAttackDmg;
}

void FragTrap::setMeleeAttackDmg(int meleeAttackDmg) {
	this->_meleeAttackDmg = meleeAttackDmg;
}

int FragTrap::getRangedAttackDmg() const {
	return this->_rangedAttackDmg;
}

void FragTrap::setRangedAttackDmg(int rangedAttackDmg) {
	this->_rangedAttackDmg = rangedAttackDmg;
}

int FragTrap::getArmorReduction() const {
	return this->_armorReduction;
}

void FragTrap::setArmorReduction(int armorReduction) {
	this->_armorReduction = armorReduction;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target) {
	if (this->_energyPoint >= 25) {
		this->setEnergyPoint(this->_energyPoint - 25);
		srand(time(NULL));
		int r = rand() % NB_ATK;
		std::string nameAtk = this->_randAtk[r][0];
		std::string typeAtk = this->_randAtk[r][1];
		std::cout << nameAtk << std::endl;
		if (typeAtk == RANGE_ATK)
			this->rangedAttack(target);
		else
			this->meleeAttack(target);
	} else
		std::cout << "Out of energy" << std::endl;
}

const std::string FragTrap::_randAtk[NB_ATK][2] = {
	{"Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!", RANGE_ATK},
	{"Flesh fireworks!", RANGE_ATK},
	{"Freezy peezy!", MELEE_ATK},
	{"Grenaaaade!", RANGE_ATK},
	{"Take that!", MELEE_ATK},
};