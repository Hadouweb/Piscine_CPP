#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() {
	std::cout << "- ZombieEvent constructor called" << std::endl;
}

ZombieEvent::~ZombieEvent() {
	std::cout << "- ZombieEvent destructor called" << std::endl;
}

void ZombieEvent::setZombieType(std::string pType) {
	this->_type = pType;
}

Zombie* ZombieEvent::newZombie(std::string name) {
	Zombie *z = new Zombie(this->_type, name);
	return z;
}

Zombie* ZombieEvent::randomChump() {
	srand(time(NULL));
	int r = rand() % 10;
	return this->newZombie(this->_nameData[r]);
}

const std::string ZombieEvent::_nameData[] = {
	"Psycho",
	"Phantom",
	"Insane",
	"Scar",
	"Glutton",
	"Hunter",
	"Disfigured",
	"Doctor",
	"Barber",
	"Chef",
};