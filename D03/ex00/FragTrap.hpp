#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include <iostream>

# define MELEE_ATK "melee"
# define RANGE_ATK "range"
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

	int getHitPoint() const;
	void setHitPoint(int hitPoint);

	int getMaxHitPoint() const;
	void setMaxHitPoint(int maxHitPoint);

	int getEnergyPoint() const;
	void setEnergyPoint(int energyPoint);

	int getMaxEnergyPoint() const;
	void setMaxEnergyPoint(int maxEnergyPoint);

	int getLevel() const;
	void setLevel(int level);

	const std::string &getName() const;
	void setName(const std::string &name);

	int getMeleeAttackDmg() const;
	void setMeleeAttackDmg(int meleeAttackDmg);

	int getRangedAttackDmg() const;
	void setRangedAttackDmg(int rangedAttackDmg);

	int getArmorReduction() const;
	void setArmorReduction(int armorReduction);


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
};

#endif