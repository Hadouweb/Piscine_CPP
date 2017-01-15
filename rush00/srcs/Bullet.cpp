#include "Bullet.hpp"

Bullet::Bullet(NcurseManager *pRender, int y, int x)
	: _render(pRender), _posY(y), _posX(x) {
	this->_render->setCell(this->_posY, this->_posX, this->getChar());
}


Bullet::Bullet(void) { }

Bullet::Bullet(Bullet const &src) {
	*this = src;
}

Bullet::~Bullet(void) {
	// Todo
}

Bullet &Bullet::operator=(Bullet const &rhs) {
	if (this != &rhs)
	{
		// Todo
	}
	return *this;
}

int Bullet::getPosY(void) const {
	return this->_posY;
}

int Bullet::getPosX(void) const {
	return this->_posX;
}

char Bullet::getChar(void) const {
	return '-';
}

void Bullet::setPosY(int y) {
	this->_posY = y;
}

void Bullet::setPosX(int x) {
	this->_posX = x;
}

void Bullet::moveX(int value) {
	if (this->_render->setCell(this->getPosY(), this->getPosX() + value, this->getChar())) {
		this->_render->setCell(this->getPosY(), this->getPosX(), ' ');
		this->setPosX(this->getPosX() + value);
	}
}


