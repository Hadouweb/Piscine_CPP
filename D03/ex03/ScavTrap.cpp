#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string pName) : ClapTrap(pName, 100, 100, 50, 50, 1, 20, 15, 3) {
	std::cout << "This time it'll be awesome, I promise! (Constructor ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "This time it'll be awesome, I promise! (Constructor Default ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	std::cout << "This time it'll be awesome, I promise! (Constructor Assignation ScavTrap)" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "I'M DEAD I'M DEAD OHMYGOD I'M DEAD! (Destructor ScavTrap)" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "This time it'll be awesome, I promise! (Constructor Copy ScavTrap)" << std::endl;
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

void ScavTrap::challengeNewcomer(std::string const &target) {
	if (this->_energyPoint >= 25) {
		this->setEnergyPoint(this->_energyPoint - 25);
		int r = rand() % NB_CHAL;
		std::string nameChal = this->_randChal[r];
		std::cout << "FR4G-TP <" << this->_name << "> " << " Hey " << target << ", " << nameChal << std::endl;
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