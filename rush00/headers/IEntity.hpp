#ifndef IENTITY_HPP
# define IENTITY_HPP

#include "NcurseManager.hpp"

class IEntity {
public:
	virtual ~IEntity() {}
	virtual int getPosY(void) const = 0;
	virtual int getPosX(void) const = 0;
	virtual char getChar(void) const = 0;
	virtual void setPosY(int y) = 0;
	virtual void setPosX(int x) = 0;
	virtual void moveX(int value) = 0;
};

#endif