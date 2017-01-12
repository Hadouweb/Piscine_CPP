#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include <iostream>

# define NB_CHAL 5

class ScavTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string pName);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);

	ScavTrap & operator=(ScavTrap const & rhs);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void challengeNewcomer(std::string const & target);

	const std::string &getName() const;

private:
	int _hitPoint;
	int _maxHitPoint;
	int _energyPoint;
	int _maxEnergyPoint;
	int _level;
	std::string _name;
	int _meleeAttackDmg;
	int _rangedAttackDmg;
	int _armorReduction;
	static const std::string _randChal[NB_CHAL];

	void setHitPoint(int hitPoint);
	void setEnergyPoint(int energyPoint);
};

#endif