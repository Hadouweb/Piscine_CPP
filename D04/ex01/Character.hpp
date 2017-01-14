#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {
public:
	Character(std::string const & name);
    Character(Character const & src);
    ~Character(void);

    Character & operator=(Character const & rhs);

	std::string const getName(void) const;
	int getAp(void) const;
	const AWeapon* getWeapon(void) const;

	void recoverAP(void);
	void equip(AWeapon *w);
	void attack(Enemy *e);

private:
	Character(void);

	std::string _name;
	int _ap;
	AWeapon *_weapon;
};

std::ostream& operator<<(std::ostream& os, const Character& c);

#endif