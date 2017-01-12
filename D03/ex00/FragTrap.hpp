#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include <iostream>

# define MELEE_ATK "melee"
# define RANGED_ATK "ranged"
# define NB_ATK 5

class FragTrap {
public:
	FragTrap(void);
	FragTrap(std::string pName);
	FragTrap(FragTrap const & src);
	~FragTrap(void);

	FragTrap & operator=(FragTrap const & rhs);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void vaulthunter_dot_exe(std::string const & target);


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
	static const std::string _randAtk[NB_ATK][2];

	void setHitPoint(int hitPoint);
	void setEnergyPoint(int energyPoint);
};

#endif