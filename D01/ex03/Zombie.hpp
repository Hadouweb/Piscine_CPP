#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:
	Zombie(void);
	~Zombie(void);

	void setType(std::string pType);
	void setName(std::string pName);
	void announce(void) const;

private:
	std::string _type;
	std::string _name;
};

#endif