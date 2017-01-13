#include "Peon.hpp"

Peon::Peon(Peon const &src) : Victim(src) {

}

Peon::Peon(std::string pName) : Victim(pName) {
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator=(Peon const &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return *this;
}

Peon::Peon(void) { }

void Peon::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}
