#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

# define MELEE_ATK "melee"
# define RANGED_ATK "ranged"
# define NB_ATK 5

class FragTrap : public virtual ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string pName);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	FragTrap &operator=(FragTrap const &rhs);

	void vaulthunter_dot_exe(std::string const &target);

private:
	static const std::string _randAtk[NB_ATK][2];
};
#endif