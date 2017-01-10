#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:
	Zombie(std::string pType, std::string pName);
	~Zombie(void);

private:
	std::string _type;
	std::string _name;

	void _announce(void) const;
};

#endif