#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

class Pony {

public:
	Pony(std::string pName);
	~Pony(void);

private:
	std::string _name;
};

#endif