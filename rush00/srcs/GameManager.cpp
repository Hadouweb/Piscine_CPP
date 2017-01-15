#include "GameManager.hpp"

GameManager::GameManager(NcurseManager *pRender) : _render(pRender) {
	this->_nbEntity = 0;
	this->_tokenSpawner = 51;
	this->_tokenDifficult = 1;
	this->_entityArray = new Enemy*[1000];
}

GameManager::GameManager(void) { }

GameManager::GameManager(GameManager const &src) {
	*this = src;
}

GameManager::~GameManager(void) {
	// Todo
}

GameManager &GameManager::operator=(GameManager const &rhs) {
	if (this != &rhs)
	{
		// Todo
	}
	return *this;
}

void GameManager::_updateEnemyArray(void) {
	int nbBullet = this->getNbEntity();
	Enemy **newEntitytArray = new Enemy*[1000];
	int j = 0;

	for (int i = 0; i < nbBullet; i++) {
		if (this->_entityArray[i]->getPosX() == 0) {
			this->_render->setCell(this->_entityArray[i]->getPosY(), this->_entityArray[i]->getPosX(), ' ');
		} else {
			newEntitytArray[j] = this->_entityArray[i];
			j++;
		}
	}
	this->_entityArray = newEntitytArray;
	this->_nbEntity = j;
}

void GameManager::enemyDie(Enemy **EnemyArrayDie, int nb) {
	int nbBullet = this->getNbEntity();
	Enemy **newEnemyArray = new Enemy*[1000];
	int k = 0;

	for (int i = 0; i < nb; i++) {
		int y1 = EnemyArrayDie[i]->getPosY();
		int x1 = EnemyArrayDie[i]->getPosX();
		for (int j = 0; j < nbBullet; j++) {
			int y2 = this->_entityArray[j]->getPosY();
			int x2 = this->_entityArray[j]->getPosX();
			if (y1 == y2 && x1 == x2) {
				this->_render->setCell(EnemyArrayDie[i]->getPosY(), EnemyArrayDie[i]->getPosX(), ' ');
			} else {
				newEnemyArray[k] = this->_entityArray[j];
				k++;
			}
		}
	}

	this->_entityArray = newEnemyArray;
	this->_nbEntity = k;
}

void GameManager::generateWave(void) {
	if (this->_tokenSpawner > 40 - (this->_tokenDifficult / 20))
	{
		int x = this->_render->getScreenWidth() - 1;
		int nb = rand() % 3 + 1;
		Enemy **entityArray = new Enemy*[nb];
		int height = this->_render->getScreenHeight();
		int minHeight = this->_render->getScreenHeightMin();

		for (int i = 0; i < nb; i++) {
			int y = (rand() % (height - minHeight - 2)) + minHeight + 1;
			entityArray[i] = new Enemy(this->_render, y, x);
			this->_entityArray[this->_nbEntity] = entityArray[i];
			this->_nbEntity++;
		}
		this->_tokenSpawner = 0;
	}
	if (_tokenDifficult < 200)
		this->_tokenDifficult++;
	this->_tokenSpawner++;
}

int GameManager::getNbEntity(void) const {
	return this->_nbEntity;
}

Enemy **GameManager::getEntityArray(void) {
	this->_updateEnemyArray();
	return this->_entityArray;
}
