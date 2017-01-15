#ifndef GAME_MANAGER_HPP
# define GAME_MANAGER_HPP

#include <iostream>
#include "IEntity.hpp"
#include "Enemy.hpp"

class GameManager {
public:
	GameManager(NcurseManager *pRender);
    GameManager(GameManager const & src);
    ~GameManager(void);
    GameManager & operator=(GameManager const & rhs);

	int getNbEntity(void) const;
	IEntity **getEntityArray(void);

private:
	GameManager(void);
	void _generateWave(void);
	IEntity **_entityArray;
	NcurseManager *_render;
	int _nbEntity;
};

#endif