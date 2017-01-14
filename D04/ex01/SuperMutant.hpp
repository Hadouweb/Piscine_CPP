#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP

#include "Enemy.hpp"
#include <iostream>

class SuperMutant : public Enemy {
public:
    SuperMutant(void);
    SuperMutant(SuperMutant const & src);
    ~SuperMutant(void);
    SuperMutant & operator=(SuperMutant const & rhs);

	void takeDamage(int value);
};

#endif