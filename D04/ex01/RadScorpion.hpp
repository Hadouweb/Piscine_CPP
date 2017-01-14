#ifndef RAD_SCORPIN_HPP
# define RAD_SCORPIN_HPP

#include "Enemy.hpp"
#include <iostream>

class RadScorpion : public Enemy {
public:
	RadScorpion(void);
	RadScorpion(RadScorpion const & src);
	~RadScorpion(void);
	RadScorpion & operator=(RadScorpion const & rhs);
};

#endif