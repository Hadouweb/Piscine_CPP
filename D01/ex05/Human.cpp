#include "Human.hpp"

Human::Human(void) {

}

Human::~Human(void) {

}

const Brain Human::getBrain() const {
	return this->_br;
}

std::string Human::identify() const {
	return this->_br.identify();
}