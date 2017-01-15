#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "IEntity.hpp"

class Enemy : public IEntity {
public:
	Enemy(NcurseManager *pRender, int y, int x);
    Enemy(Enemy const & src);

    ~Enemy(void);

    Enemy & operator=(Enemy const & rhs);

	int getPosY(void) const;
	int getPosX(void) const;
	char getChar(void) const;
	void moveX(int value);
	void setPosY(int y);
	void setPosX(int x);

private:
	Enemy(void);
	NcurseManager *_render;
	int _posY;
	int _posX;
};

#endif