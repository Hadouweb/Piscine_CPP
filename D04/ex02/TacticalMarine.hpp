#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
public:
    TacticalMarine(void);
    TacticalMarine(TacticalMarine const & src);
    ~TacticalMarine(void);

    TacticalMarine & operator=(TacticalMarine const & rhs);

	ISpaceMarine *clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif