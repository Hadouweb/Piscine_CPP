#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string pName)  : _name(pName) {
	std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: CL4P-TP, Hyperion (Constructor)" << std::endl;
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 50;
	this->_maxEnergyPoint = 50;
	this->_level = 1;
	this->_meleeAttackDmg = 20;
	this->_rangedAttackDmg = 15;
	this->_armorReduction = 3;
}

ScavTrap::ScavTrap(void) : _name("Unknown") {
	std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: CL4P-TP, Hyperion (Constructor Default)" << std::endl;
	this->_hitPoint = 100;
	this->_maxHitPoint = 100;
	this->_energyPoint = 50;
	this->_maxEnergyPoint = 50;
	this->_level = 1;
	this->_meleeAttackDmg = 20;
	this->_rangedAttackDmg = 15;
	this->_armorReduction = 3;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: CL4P-TP, Hyperion (Constructor Assignation)" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "I'M DEAD I'M DEAD OHMYGOD I'M DEAD! (Destructor)" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: CL4P-TP, Hyperion (Constructor Copy)" << std::endl;
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

void ScavTrap::rangedAttack(std::string const &target) {
	std::cout << "FR4G-TP <" << this->_name << "> attacks <" << target <<
	"> at range, causing <" << this->_rangedAttackDmg << "> points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target) {
	std::cout << "FR4G-TP <" << this->_name << "> attacks <" << target <<
	"> at melee, causing <" << this->_meleeAttackDmg << "> points of damage !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	int reduceDmg = amount - this->_armorReduction;
	if (reduceDmg > 0)
		this->setHitPoint(this->_hitPoint - reduceDmg);
	std::cout << "FR4G-TP <" << this->_name << "> take <" << reduceDmg << "> points of damage !" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	std::cout << "FR4G-TP <" << this->_name << "> is repaired <" << amount <<
			  "> points of damage !" << std::endl;
	this->setHitPoint(this->_hitPoint + amount);
}

const std::string &ScavTrap::getName() const {
	return this->_name;
}

void ScavTrap::setHitPoint(int hitPoint) {
	if (hitPoint > this->_maxHitPoint)
		this->_energyPoint = this->_maxHitPoint;
	else if (hitPoint <= 0)
		this->_energyPoint = 0;
	else
		this->_energyPoint = hitPoint;
}

void ScavTrap::setEnergyPoint(int energyPoint) {
	if (energyPoint > this->_maxEnergyPoint)
		this->_energyPoint = this->_maxEnergyPoint;
	else if (energyPoint <= 0)
		this->_energyPoint = 0;
	else
		this->_energyPoint = energyPoint;
}

void ScavTrap::challengeNewcomer(std::string const &target) {
	if (this->_energyPoint >= 25) {
		this->setEnergyPoint(this->_energyPoint - 25);
		srand(time(NULL));
		int r = rand() % NB_CHAL;
		std::string nameChal = this->_randChal[r];
		std::cout << "FR4G-TP <" << this->_name << ">" << " Hey " << target << ", " << nameChal << std::endl;
	} else
		std::cout << "FR4G-TP <" << this->_name << "> is out of energy" << std::endl;
}

const std::string ScavTrap::_randChal[NB_CHAL] = {
	"You versus me! Me versus you! Either way",
	"I will prove to you my robotic superiority!",
	"Dance battle! Or, you know... regular battle.",
	"Man versus machine! Very tiny streamlined machine!",
	"Care to have a friendly duel?",
};