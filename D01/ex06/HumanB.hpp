#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
public:
	HumanB(std::string pName);
	~HumanB(void);

	void attack(void) const;
	void setWeapon(Weapon pClub);

private:
	std::string _name;
	Weapon *_club;
};

#endif