#include "Brain.hpp"
#include <sstream>

Brain::Brain(void) {
	std::stringstream ss;
	ss << this;
	this->_id = ss.str();
	for(int i = 0; this->_id[i]; i++)
		this->_id [i] = toupper(this->_id[i]);
}

Brain::~Brain(void) {

}

std::string Brain::identify(void) const {`
	return this->_id;
}