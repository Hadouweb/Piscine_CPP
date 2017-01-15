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
	Enemy **getEntityArray(void);
	void generateWave(void);
	void enemyDie(Enemy **EnemyArrayDie, int nb);

private:
	GameManager(void);
	void _updateEnemyArray(void);
	Enemy **_entityArray;
	NcurseManager *_render;
	int _nbEntity;
	int _tokenSpawner;
	int _tokenDifficult;
};

#endif