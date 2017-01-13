#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string pName) : ClapTrap(pName) {
	std::cout << "(Constructor SuperTrap)" << std::endl;
	this->_hitPoint = FragTrap::_hitPoint;
	this->_maxHitPoint = FragTrap::_maxHitPoint;
	this->_energyPoint = NinjaTrap::_energyPoint;
	this->_maxEnergyPoint = NinjaTrap::_maxEnergyPoint;
	this->_level = 1;
	this->_meleeAttackDmg = NinjaTrap::_meleeAttackDmg;
	this->_rangedAttackDmg = FragTrap::_rangedAttackDmg;
	this->_armorReduction = FragTrap::_armorReduction;
}

SuperTrap::SuperTrap(void) : ClapTrap() {
	std::cout << "(Constructor Default SuperTrap)" << std::endl;
	this->_hitPoint = FragTrap::_hitPoint;
	this->_maxHitPoint = FragTrap::_maxHitPoint;
	this->_energyPoint = NinjaTrap::_energyPoint;
	this->_maxEnergyPoint = NinjaTrap::_maxEnergyPoint;
	this->_level = 1;
	this->_meleeAttackDmg = NinjaTrap::_meleeAttackDmg;
	this->_rangedAttackDmg = FragTrap::_rangedAttackDmg;
	this->_armorReduction = FragTrap::_armorReduction;
}

SuperTrap::SuperTrap(SuperTrap const &src) : ClapTrap(src) {
	std::cout << "(Constructor Assignation SuperTrap)" << std::endl;
	*this = src;
}

SuperTrap::~SuperTrap(void) {
	std::cout << "(Destructor SuperTrap)" << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &rhs) {
	std::cout << "(Constructor Copy SuperTrap)" << std::endl;
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
