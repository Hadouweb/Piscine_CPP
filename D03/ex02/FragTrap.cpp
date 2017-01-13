#include "FragTrap.hpp"

FragTrap::FragTrap(std::string pName) : ClapTrap(pName, 100, 100, 100, 100, 1, 30, 20, 5) {
	std::cout << "Let's get this party started! (Constructor FragTrap)" << std::endl;
}

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "Let's get this party started! (Constructor Default FragTrap)" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	std::cout << "Let's get this party started! (Constructor Assignation FragTrap)" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void) {
	std::cout << "Are you god? Am I dead? (Destructor FragTrap)" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &rhs) {
	std::cout << "Let's get this party started! (Constructor Copy FragTrap)" << std::endl;
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

void FragTrap::vaulthunter_dot_exe(std::string const &target) {
	if (this->_energyPoint >= 25) {
		this->setEnergyPoint(this->_energyPoint - 25);
		int r = rand() % NB_ATK;
		std::string nameAtk = this->_randAtk[r][0];
		std::string typeAtk = this->_randAtk[r][1];
		std::cout << "FR4G-TP <" << this->_name << "> " << nameAtk << std::endl;
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