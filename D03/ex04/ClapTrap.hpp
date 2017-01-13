#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap {
public:
    ClapTrap(void);
	ClapTrap(std::string pName);
    ClapTrap(ClapTrap const & src);
    ~ClapTrap(void);

    ClapTrap & operator=(ClapTrap const & rhs);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	const std::string &getName() const;

protected:
	int _hitPoint;
	int _maxHitPoint;
	int _energyPoint;
	int _maxEnergyPoint;
	int _level;
	std::string _name;
	int _meleeAttackDmg;
	int _rangedAttackDmg;
	int _armorReduction;

	void setHitPoint(int hitPoint);
	void setEnergyPoint(int energyPoint);
};

#endif