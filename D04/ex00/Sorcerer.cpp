#include "Sorcerer.hpp"

Sorcerer::Sorcerer(Sorcerer const &src) {
	*this = src;
}

Sorcerer::Sorcerer(std::string pName, std::string pTitle)
	: _name(pName), _title(pTitle) {
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(void) {
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_title = rhs._title;
	}
	return *this;
}

Sorcerer::Sorcerer(void) { }

const std::string &Sorcerer::getName(void) const {
	return this->_name;
}

const std::string &Sorcerer::getTitle(void) const {
	return this->_title;
}

std::ostream &operator<<(std::ostream &os, const Sorcerer &s) {
	os << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies !" << std::endl;
	return os;
}

void Sorcerer::polymorph(Victim const & v) const {
	v.getPolymorphed();
}
