#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int 	main(void)
{
	Zombie z1("Shaman", "Thral");

	ZombieEvent *z2 = new ZombieEvent();
	z2->setZombieType("Rogue");
	z2->newZombie("Jhon");

	Zombie *z3 = z2->randomChump();

	delete z2;
	delete z3;

	return 0;
}