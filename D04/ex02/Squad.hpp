#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include <iostream>

class Squad : public ISquad {
public:
    Squad(void);
    Squad(Squad const & src);
    ~Squad(void);

    Squad & operator=(Squad const & rhs);

	int getCount(void) const;
	ISpaceMarine *getUnit(int i) const;
	int push(ISpaceMarine *marine);

private:
	int _nbUnit;
	ISpaceMarine **_unitArray;
};

#endif