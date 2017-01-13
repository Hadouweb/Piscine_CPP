#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
		_name("Unknown"),
		_hitPoint(0),
		_maxHitPoint(0),
		_energyPoint(0),
		_maxEnergyPoint(0),
		_level(0),
		_meleeAttackDmg(0),
		_rangedAttackDmg(0),
		_armorReduction(0) {
	std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: CL4P-TP, Hyperion (Constructor Default ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: CL4P-TP, Hyperion (Constructor Assignation ClapTrap)" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(
	std::string pName,
	int pHitPoints,
	int pMaxHitPoint,
	int pEnergyPoint,
	int pMaxEnergyPoint,
	int pLevel,
	int pMeleeAttackDmg,
	int pRangedAttackDmg,
	int pArmorReduction
	) :
		_name(pName),
		_hitPoint(pHitPoints),
		_maxHitPoint(pMaxHitPoint),
		_energyPoint(pEnergyPoint),
		_maxEnergyPoint(pMaxEnergyPoint),
		_level(pLevel),
		_meleeAttackDmg(pMeleeAttackDmg),
		_rangedAttackDmg(pRangedAttackDmg),
		_armorReduction(pArmorReduction)
{
	std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: CL4P-TP, Hyperion (Constructor ClapTrap)" << std::endl;
	srand(time(0));
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Argh arghargh death gurgle gurglegurgle urgh... death. (Destructor ClapTrap)" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: CL4P-TP, Hyperion (Constructor Copy ClapTrap)" << std::endl;
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

void ClapTrap::rangedAttack(std::string const &target) {
	std::cout << "FR4G-TP <" << this->_name << "> attacks <" << target <<
			  "> at range, causing <" << this->_rangedAttackDmg << "> points of damage !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target) {
	std::cout << "FR4G-TP <" << this->_name << "> attacks <" << target <<
			  "> at melee, causing <" << this->_meleeAttackDmg << "> points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	int reduceDmg = amount - this->_armorReduction;
	if (reduceDmg > 0)
		this->setHitPoint(this->_hitPoint - reduceDmg);
	std::cout << "FR4G-TP <" << this->_name << "> take <" << reduceDmg << "> points of damage !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "FR4G-TP <" << this->_name << "> is repaired <" << amount <<
			  "> points of damage !" << std::endl;
	this->setHitPoint(this->_hitPoint + amount);
}

const std::string &ClapTrap::getName() const {
	return this->_name;
}

void ClapTrap::setHitPoint(int hitPoint) {
	if (hitPoint > this->_maxHitPoint)
		this->_energyPoint = this->_maxHitPoint;
	else if (hitPoint <= 0)
		this->_energyPoint = 0;
	else
		this->_energyPoint = hitPoint;
}

void ClapTrap::setEnergyPoint(int energyPoint) {
	if (energyPoint > this->_maxEnergyPoint)
		this->_energyPoint = this->_maxEnergyPoint;
	else if (energyPoint <= 0)
		this->_energyPoint = 0;
	else
		this->_energyPoint = energyPoint;
}