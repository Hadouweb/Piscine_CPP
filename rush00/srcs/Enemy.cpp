#include "Enemy.hpp"

Enemy::Enemy(NcurseManager *pRender, int y, int x)
	: _render(pRender), _posY(y), _posX(x) {
	this->_render->setCell(this->_posY, this->_posX, this->getChar());
}

Enemy::Enemy(void) { }

Enemy::Enemy(Enemy const &src) {
	*this = src;
}

Enemy::~Enemy(void) {

}

Enemy &Enemy::operator=(Enemy const &rhs) {
	if (this != &rhs)
	{
		// Todo
	}
	return *this;
}

int Enemy::getPosY(void) const {
	return this->_posY;
}

int Enemy::getPosX(void) const {
	return this->_posX;
}

char Enemy::getChar(void) const {
	return 'x';
}

void Enemy::setPosY(int y) {
	this->_posY = y;
}

void Enemy::setPosX(int x) {
	this->_posX = x;
}

void Enemy::moveX(int value) {
	if (this->_render->setCell(this->getPosY(), this->getPosX() - value, this->getChar())) {
		this->_render->setCell(this->getPosY(), this->getPosX(), ' ');
		this->setPosX(this->getPosX() - value);
	}
}