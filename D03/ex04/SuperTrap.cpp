#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string pName) : ClapTrap(pName, 100, 100, 120, 120, 1, 60, 20, 5) {
	std::cout << "(Constructor SuperTrap)" << std::endl;
}

SuperTrap::SuperTrap(void) : ClapTrap() {
	std::cout << "(Constructor Default SuperTrap)" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &src) : ClapTrap(src) {
	std::cout << "(Constructor Assignation SuperTrap)" << std::endl;
	*this = src;
}

SuperTrap::~SuperTrap(void) {
	std::cout << "(Destructor SuperTrap)" << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &rhs) {
	std::cout << "(Constructor Copy SuperTrap)" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}
