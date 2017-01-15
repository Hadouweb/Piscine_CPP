#include "Player.hpp"

Player::Player(NcurseManager *pRender) : _render(pRender) {
	this->_posX = 0;
	int midY = this->_render->getScreenHeight() / 2;
	this->_posY = midY;
	this->_render->setCursorY(midY);
	this->_nbBullet = 0;
	this->_bulletArray = new Bullet*[1000];
}

Player::Player(void) { }

Player::Player(Player const &src) {
	*this = src;
}

Player::~Player(void) {
	if (this->_nbBullet > 0)
		delete [] this->_bulletArray;
	// Todo
}

Player &Player::operator=(Player const &rhs) {
	if (this != &rhs)
	{
		// Todo
	}
	return *this;
}

void Player::_updateBulletArray(void) {
	int nbBullet = this->getNbBullet();
	Bullet **newBulletArray = new Bullet*[1000];
	int j = 0;

	for (int i = 0; i < nbBullet; i++) {
		if (this->_bulletArray[i]->getPosX() + 1 == this->_render->getScreenWidth()) {
			this->_render->setCell(this->_bulletArray[i]->getPosY(), this->_bulletArray[i]->getPosX(), ' ');
			delete this->_bulletArray[i];
		} else {
			newBulletArray[j] = this->_bulletArray[i];
			j++;
		}
	}
	this->_bulletArray = newBulletArray;
	this->_nbBullet = j;
}

Bullet **Player::getBulletArray(void) {
	this->_updateBulletArray();
	return this->_bulletArray;
}

int Player::getNbBullet(void) const {
	return this->_nbBullet;
}

void Player::shoot(void) {
	if (this->getPosX() < this->_render->getScreenWidth() - 1) {
		this->_bulletArray[this->_nbBullet] = new Bullet(this->_render, this->getPosY(), this->getPosX() + 1);
		this->_nbBullet++;
	}
}

int Player::getPosY(void) const {
	return this->_posY;
}

int Player::getPosX(void) const {
	return this->_posX;
}

char Player::getChar(void) const {
	return '>';
}

void Player::setPosY(int y) {
	this->_posY = y;
}

void Player::setPosX(int x) {
	this->_posX = x;
}

void Player::moveDown(void) {
	int newPos = this->_render->getCursorY() + 1;
	if (this->_render->setCursorY(newPos))
		this->setPosY(newPos);
}

void Player::moveUp(void) {;
	int newPos = this->_render->getCursorY() - 1;
	if (this->_render->setCursorY(newPos))
		this->setPosY(newPos);
}

void Player::moveLeft(void) {
	int newPos = this->_render->getCursorX() - 1;
	if (this->_render->setCursorX(newPos))
		this->setPosX(newPos);
}

void Player::moveRight(void) {
	int newPos = this->_render->getCursorX() + 1;
	if (this->_render->setCursorX(newPos))
		this->setPosX(newPos);
}

void Player::moveX(int value) {
	if (value)
		;
}
