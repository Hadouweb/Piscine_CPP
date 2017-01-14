#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type)
	: _type(type), _hp(hp) {

}

Enemy::Enemy(Enemy const &src) {
	*this = src;
}

Enemy::~Enemy(void) {

}

std::string const Enemy::getType(void) const {
	return this->_type;
}

int Enemy::getHP(void) const {
	return this->_hp;
}

void Enemy::takeDamage(int value) {
	if (value < 0)
		return ;
	this->_hp -= value;
}

Enemy &Enemy::operator=(Enemy const &rhs) {
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_hp = rhs._hp;
	}
	return *this;
}

Enemy::Enemy(void) {

}
