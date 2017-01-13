#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

# define NB_CHAL 5

class ScavTrap : public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string pName);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);

	ScavTrap & operator=(ScavTrap const & rhs);

	void challengeNewcomer(std::string const & target);

private:
	static const std::string _randChal[NB_CHAL];
};

#endif