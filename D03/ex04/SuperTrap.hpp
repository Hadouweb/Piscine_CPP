#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
public:
    SuperTrap(void);
	SuperTrap(std::string pName);
    SuperTrap(SuperTrap const & src);
    ~SuperTrap(void);

    SuperTrap & operator=(SuperTrap const & rhs);
};

#endif