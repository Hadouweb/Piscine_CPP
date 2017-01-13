#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string pName) : ClapTrap(pName) {
	std::cout << "I'm a robot ninja... (Constructor NinjaTrap)" << std::endl;
	this->_hitPoint = 60;
	this->_maxHitPoint = 60;
	this->_energyPoint = 120;
	this->_maxEnergyPoint = 120;
	this->_level = 1;
	this->_meleeAttackDmg = 60;
	this->_rangedAttackDmg = 5;
	this->_armorReduction = 0;
}

NinjaTrap::NinjaTrap(void) : ClapTrap()  {
	std::cout << "I'm a robot ninja... (Constructor Default NinjaTrap)" << std::endl;
	this->_hitPoint = 60;
	this->_maxHitPoint = 60;
	this->_energyPoint = 120;
	this->_maxEnergyPoint = 120;
	this->_level = 1;
	this->_meleeAttackDmg = 60;
	this->_rangedAttackDmg = 5;
	this->_armorReduction = 0;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src) {
	std::cout << "I'm a robot ninja... (Constructor Assignation NinjaTrap)" << std::endl;
	*this = src;
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << "Go on without me! (Destructor NinjaTrap)" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs) {
	std::cout << "I'm a robot ninja... (Constructor Copy FragTrap)" << std::endl;
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

void NinjaTrap::ninjaShoebox(FragTrap &ft) {
	if (this->_energyPoint >= 25) {
		this->setEnergyPoint(this->_energyPoint - 25);
		int r = rand() % NB_ATK;
		std::string nameAtk = this->_randAtkFrag[r];
		std::cout << "FR4G-TP <" << this->_name << "> " << nameAtk << std::endl;
		this->meleeAttack(ft.getName());
	} else
		std::cout << "FR4G-TP <" << this->_name << "> is out of energy" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &st) {
	if (this->_energyPoint >= 25) {
		this->setEnergyPoint(this->_energyPoint - 25);
		int r = rand() % NB_ATK;
		std::string nameAtk = this->_randAtkNScav[r];
		std::cout << "FR4G-TP <" << this->_name << "> " << nameAtk << std::endl;
		this->meleeAttack(st.getName());
	} else
		std::cout << "FR4G-TP <" << this->_name << "> is out of energy" << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &nt) {
	if (this->_energyPoint >= 25) {
		this->setEnergyPoint(this->_energyPoint - 25);
		int r = rand() % NB_ATK;
		std::string nameAtk = this->_randAtkNinjaTrap[r];
		std::cout << "FR4G-TP <" << this->_name << "> " << nameAtk << std::endl;
		this->meleeAttack(nt.getName());
	} else
		std::cout << "FR4G-TP <" << this->_name << "> is out of energy" << std::endl;
}

const std::string NinjaTrap::_randAtkNinjaTrap[NB_ATK] = {
		"Shoot him... he's the real one...",
		"Crit-i-cal!",
		"RUN FOR YOUR LIIIIIVES!!!",
		"Wow, did I really do that?",
		"I AM ON FIRE!!! OH GOD, PUT ME OUT!!!",
};

const std::string NinjaTrap::_randAtkFrag[NB_ATK] = {
		"I'm invisible!",
		"Eww! Cool.",
		"Oooh! Gigabits!",
		"Hyah!",
		"Look out, a Badass!",
};

const std::string NinjaTrap::_randAtkNScav[NB_ATK] = {
		"This is why I was built!",
		"That was a close one!",
		"Holy moly!",
		"Ha ha ha! Suck it!",
		"Don't tell me that wasn't awesome!",
};