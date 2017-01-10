#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int nb) : _nbZ(nb) {
	this->_horde = new Zombie[this->_nbZ];
	for (int i = 0; i < this->_nbZ; i++)
	{
		this->_horde[i].setName(this->_getRandomName(i));
		this->_horde[i].setType("Horde");
	}
	this->_announce();
}

ZombieHorde::~ZombieHorde() {
	delete [] this->_horde;
}

void ZombieHorde::_announce() const {
	for (int i = 0; i < this->_nbZ; i++)
	{
		this->_horde[i].announce();
	}
}

std::string ZombieHorde::_getRandomName(int i) const {
	srand(time(NULL) + i);
	int r = rand() % 10;
	return (this->_nameData[r]);
}

const std::string ZombieHorde::_nameData[] = {
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