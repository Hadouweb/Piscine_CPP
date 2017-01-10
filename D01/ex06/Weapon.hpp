#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
public:
	Weapon(std::string pType);
	~Weapon(void);

	const std::string& getType(void) const;
	void setType(std::string pType);

private:
	std::string _type;
};

#endif