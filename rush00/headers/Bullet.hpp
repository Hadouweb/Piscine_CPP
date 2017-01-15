#ifndef BULLET_HPP
# define BULLET_HPP

#include "IEntity.hpp"

class Bullet : public IEntity {
public:
	Bullet(NcurseManager *pRender, int y, int x);
	Bullet(Bullet const & src);

    ~Bullet(void);

    Bullet & operator=(Bullet const & rhs);

	int getPosY(void) const;
	int getPosX(void) const;
	void moveX(int value);
	char getChar(void) const;
	void setPosY(int y);
	void setPosX(int x);

private:
	Bullet(void);
	NcurseManager *_render;
	int _posY;
	int _posX;
};

#endif