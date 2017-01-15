#include "GameEngine.hpp"

GameEngine::GameEngine(void) {
	this->_currentKey = 0;
	this->_render = new NcurseManager();
	this->_createPlayer();
	this->_createGameManager();
	srand(time(NULL));
}

GameEngine::GameEngine(GameEngine const &src) {
	*this = src;
}

GameEngine::~GameEngine(void) {
	delete this->_render;
	// Todo
}

GameEngine &GameEngine::operator=(GameEngine const &rhs) {
	if (this != &rhs)
	{
		// Todo
	}
	return *this;
}

void GameEngine::_createGameManager(void) {
	this->_gm = new GameManager(this->_render);
}

void GameEngine::_createPlayer(void) {
	this->_player = new Player(this->_render);
	this->_render->draw();
}

void GameEngine::_readInput(void) {
	this->_currentKey = 0;
	if (NcurseManager::haveEvent()) {
		int ch = getch();
		if (ch == '\033') {
			getch(); // SKIP '[' for arrow key
			this->_currentKey = getch();
		} else
			this->_currentKey = ch;
		//std::cout << "[key]:" << this->_currentKey << std::endl;
	}
}

void GameEngine::_endGame(void) {
	delete this->_render;
	exit(0);
}

void GameEngine::_updateKey(void) {
	if (this->_currentKey == KEY_DOWN_ARROW)
		this->_player->moveDown();
	else if (this->_currentKey == KEY_UP_ARROW)
		this->_player->moveUp();
	else if (this->_currentKey == KEY_LEFT_ARROW)
		this->_player->moveLeft();
	else if (this->_currentKey == KEY_RIGHT_ARROW)
		this->_player->moveRight();
	else if (this->_currentKey == KEY_SPACE)
		this->_player->shoot();
	else if (this->_currentKey == KEY_ESC)
		this->_endGame();
}


void GameEngine::_updateBullet(void) {
	int nbBullet = this->_player->getNbBullet();
	Bullet **bulletArray = this->_player->getBulletArray();

	for (int i = 0; i < nbBullet; i++) {
		if (bulletArray[i] != NULL)
			bulletArray[i]->moveX(1);
	}
}

void GameEngine::_updateEnemy(void) {
	int nbEntity = this->_gm->getNbEntity();
	IEntity **entityArray = this->_gm->getEntityArray();

	for (int i = 0; i < nbEntity; i++) {
		if (entityArray[i] != NULL)
			entityArray[i]->moveX(1);
	}
}

void GameEngine::startGame(void) {
	this->_gameLoop();
}

void GameEngine::_gameLoop(void) {
	while (42)
	{
		this->_update();
	}
}

void GameEngine::_update(void) {
	this->_readInput();
	this->_updateKey();
	this->_updateBullet();
	this->_updateEnemy();
	usleep(10000);
	this->_render->draw();
}
