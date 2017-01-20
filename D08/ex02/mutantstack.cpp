#include "mutantstack.hpp"

MutantStack::MutantStack(void) {

}

MutantStack::MutantStack(MutantStack const &src) {
	*this = src;
}

MutantStack::~MutantStack(void) {

}

MutantStack &MutantStack::operator=(MutantStack const &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

MutantStack::iterator MutantStack::begin() {
	return MutantStack::iterator();
}

MutantStack::iterator MutantStack::end() {
	return MutantStack::iterator();
}

MutantStack::iterator::iterator(void) : _it(0) { }

MutantStack::iterator::iterator(const MutantStack::iterator &src) {
	*this = src;
}

MutantStack::iterator::~iterator(void) { }

MutantStack::iterator &
MutantStack::iterator::operator=(const MutantStack::iterator &rhs) {
	if (this != &rhs) {
		this->_it = rhs._it;
	}
	return *this;
}

MutantStack::iterator &MutantStack::iterator::operator++(void) {
	++(this->_it);
	return *this;
}

MutantStack::iterator &MutantStack::iterator::operator--(void) {
	--(this->_it);
	return *this;
}

MutantStack::iterator MutantStack::iterator::operator++(int) {
	MutantStack::iterator it = *this;
	++(this->_it);
	return it;
}

MutantStack::iterator MutantStack::iterator::operator--(int) {
	MutantStack::iterator it = *this;
	--(this->_it);
	return it;
}
