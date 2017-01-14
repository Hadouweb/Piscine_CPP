#include "Squad.hpp"
#include "ISpaceMarine.hpp"

Squad::Squad(void) : _nbUnit(0), _unitArray(NULL) {

}

Squad::Squad(Squad const &src) {
	*this = src;
	this->_nbUnit = src._nbUnit;
	for (int j = 0; j < this->_nbUnit; j++) {
		this->_unitArray[j] = src._unitArray[j];
	}
}

Squad::~Squad(void) {
	for (int j = 0; j < this->_nbUnit; j++) {
		if (this->_unitArray[j])
			delete this->_unitArray[j];
	}
	delete [] this->_unitArray;
}

Squad &Squad::operator=(Squad const &rhs) {
	if (this != &rhs)
	{
		this->_nbUnit = rhs._nbUnit;
		for (int j = 0; j < this->_nbUnit; j++) {
			if (this->_unitArray[j] != NULL)
				delete this->_unitArray[j];
			this->_unitArray[j] = rhs._unitArray[j];
		}
	}
	return *this;
}

int Squad::getCount(void) const {
	return this->_nbUnit;
}

ISpaceMarine *Squad::getUnit(int i) const {
	for (int j = 0; j < this->_nbUnit; j++) {
		if (j == i)
			return this->_unitArray[j];
	}
	return NULL;
}

int Squad::push(ISpaceMarine *marine) {
	if (marine != NULL)
	{
		ISpaceMarine **tmpUnitArray = new ISpaceMarine*[this->_nbUnit + 1];
		for (int j = 0; j < this->_nbUnit; j++) {
			tmpUnitArray[j] = this->_unitArray[j];
		}
		delete [] this->_unitArray;
		tmpUnitArray[this->_nbUnit] = marine;
		this->_nbUnit++;
		this->_unitArray = tmpUnitArray;
	}
	return this->getCount();
}
