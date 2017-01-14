#include <iostream>
#include "Character.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	Character* thor = new Character("Thor");
	Character* copyThor = thor;

	std::cout << *copyThor;

	std::cout << *zaz;

	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	SuperMutant* sp = new SuperMutant();
	copyThor->equip(pr);
	std::cout << *copyThor;
	copyThor->attack(sp);
	std::cout << *copyThor;

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	return 0;
}