#ifndef GAME_ENGINE_HPP
# define GAME_ENGINE_HPP

#include <ncurses.h>
#include <iostream>
#include "NcurseManager.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "GameManager.hpp"

class GameEngine {
public:
    GameEngine(void);
    GameEngine(GameEngine const & src);
    ~GameEngine(void);
    GameEngine & operator=(GameEngine const & rhs);

	void startGame();

private:
	void _createPlayer(void);
	void _createGameManager(void);
	void _update(void);
	void _updateKey(void);
	void _updateBullet(void);
	void _updateEnemy(void);
	void _readInput(void);
	void _endGame(void);
	void _gameLoop(void);
	NcurseManager *_render;
	int _currentKey;
	Player *_player;
	GameManager *_gm;
};

#endif