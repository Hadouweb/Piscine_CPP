#include "GameManager.hpp"

GameManager::GameManager(NcurseManager *pRender) : _render(pRender) {
	this->_nbEntity = 0;
	this->_entityArray = new IEntity*[1000];
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

void GameManager::_generateWave(void) {
	int nb = this->getNbEntity();
	int x = this->_render->getScreenWidth() - 1;

	for (int i = 0; i < nb; i++) {
		int y = rand() % (this->_render->getScreenHeight() - 2) + 1;
		this->_entityArray[i] = new Enemy(this->_render, y, x);
	}
}

int GameManager::getNbEntity(void) const {
	return this->_nbEntity;
}

IEntity **GameManager::getEntityArray(void) {
	return this->_entityArray;
}
