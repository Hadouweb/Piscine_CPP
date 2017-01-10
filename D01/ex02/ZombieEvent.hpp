#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {
public:
	ZombieEvent(void);
	~ZombieEvent(void);

	void setZombieType(std::string pType);
	Zombie* newZombie(std::string name);
	Zombie* randomChump(void);

private:
	static const std::string _nameData[];
	std::string _type;
};

#endif