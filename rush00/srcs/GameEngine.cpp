#include "GameEngine.hpp"

GameEngine::GameEngine(void) {
	this->_score = 0;
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
	delete this->_player;
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
	this->_render->draw(0);
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
	Enemy **entityArray = this->_gm->getEntityArray();

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

void GameEngine::_updateCollision(void) {
	int nbBullet = this->_player->getNbBullet();
	int nbEntity = this->_gm->getNbEntity();

	Bullet **bulletArray = this->_player->getBulletArray();
	Enemy **entityArray = this->_gm->getEntityArray();
	Bullet **bulletDie = new Bullet*[1000];
	Enemy **entityDie = new Enemy*[1000];
	int nbBulletDie = 0;
	int nbEntityDie = 0;

	if (nbEntity > 0 && nbBullet > 0) {

		for (int i = 0; i < nbBullet; i++) {
			if (bulletArray[i] != NULL) {
				int bulletY = bulletArray[i]->getPosY();
				int bulletX = bulletArray[i]->getPosX();

				for (int j = 0; j < nbEntity; j++) {

					if (entityArray[j] != NULL) {
						int entityY = entityArray[j]->getPosY();
						int entityX = entityArray[j]->getPosX();
						if (bulletY == entityY && (bulletX + 1 == entityX || bulletX == entityX)) {
							bulletDie[nbBulletDie] = bulletArray[i];
							entityDie[nbEntityDie] = entityArray[j];
							nbBulletDie++;
							nbEntityDie++;
							this->_score++;
							break ;
						}
					}

				}
			}
		}
	}


	if (nbBulletDie > 0)
		this->_player->bulletDie(bulletDie, nbBulletDie);
	if (nbEntityDie > 0)
		this->_gm->enemyDie(entityDie, nbEntityDie);
}

bool GameEngine::_isDie() {
	char **map = this->_render->getMap();
	int playerY = this->_player->getPosY();
	int playerX = this->_player->getPosX();
	if (map[playerY][playerX] != this->_player->getChar()) {
		return TRUE;
	}
	return FALSE;
}

void GameEngine::_update(void) {
	std::clock_t start = std::clock();
	if (this->_render->isResized() || this->_isDie())
		this->_endGame();
	this->_readInput();
	this->_updateKey();
	this->_updateEnemy();
	this->_updateBullet();
	this->_updateCollision();
	this->_gm->generateWave();
	this->_render->draw(this->_score);
	int end = int(std::clock() - start);
	usleep(20000 - end);
}
