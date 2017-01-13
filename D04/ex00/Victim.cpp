#include "Victim.hpp"

Victim::Victim(Victim const &src) {
	*this = src;
}

Victim::Victim(std::string pName) : _name(pName) {
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::~Victim(void) {
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

Victim &Victim::operator=(Victim const &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return *this;
}

Victim::Victim(void) { }

const std::string &Victim::getName(void) const {
	return this->_name;
}

std::ostream &operator<<(std::ostream &os, const Victim &s) {
	os << "I'm " << s.getName() << " and I like otters !"  << std::endl;;
	return os;
}

void Victim::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}
