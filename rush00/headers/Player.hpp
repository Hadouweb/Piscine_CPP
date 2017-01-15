#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "IEntity.hpp"
#include "Bullet.hpp"

class Player : public IEntity {
public:
	Player(NcurseManager *pRender);
    Player(Player const & src);
    ~Player(void);

    Player & operator=(Player const & rhs);

	int getPosY(void) const;
	int getPosX(void) const;
	char getChar(void) const;
	void setPosY(int y);
	void setPosX(int x);
	void moveDown(void);
	void moveUp(void);
	void moveLeft(void);
	void moveRight(void);
	Bullet **getBulletArray(void);
	int getNbBullet(void) const;
	void moveX(int value);
	void shoot(void);

private:
	Player(void);
	void _updateBulletArray(void);
	NcurseManager *_render;
	int _posY;
	int _posX;
	Bullet **_bulletArray;
	int _nbBullet;
};

#endif