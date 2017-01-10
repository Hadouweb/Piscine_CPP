#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
public:
	HumanA(std::string pName, Weapon pClub);
	~HumanA(void);

	void attack(void) const;

private:
	std::string _name;
	const Weapon& _club;
};

#endif