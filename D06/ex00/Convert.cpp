#include "Convert.hpp"

Convert::Convert(std::string pBase)
	: _base(pBase) {

	if (this->isInteger())
		std::cout << this->_base << " is a int : " << this->_intValue << std::endl;
	else
		std::cout << this->_base << " is not a int" << std::endl;

	if (this->isChar())
		std::cout << this->_base << " is a char : " << this->_charValue << std::endl;
	else
		std::cout << this->_base << " is not a char" << std::endl;


	if (_charValue || _floatValue || _doubleValue)
		;
}

Convert::Convert(Convert const &src) {
	*this = src;
}

Convert::~Convert(void) { }

Convert &Convert::operator=(Convert const &rhs) {
	if (this != &rhs) {
		this->_base = rhs._base;
	}
	return *this;
}

Convert::Convert(void) { }

std::string Convert::getBase(void) const {
	return this->_base;
}

bool Convert::isInteger(void) {
	std::string b = this->getBase();

	if (b.empty())
		return false;
	if (!isdigit(b[0]) && b[0] != '-' && b[0] != '+')
		return false;
	for (int i = 1; b[i]; i++) {
		if (!isdigit(b[i]))
			return false;
	}

	char *end;
	long ret = std::strtol(b.c_str(), &end, 10);

	if (ret < INT_MIN || ret > INT_MAX)
		return false;

	this->_intValue = ret;

	return true;
}

bool Convert::isChar(void) {
	std::string b = this->getBase();

	if (b.length() != 1)
		return false;
	if (!isalpha(b[0]) || !isprint(b[0]))
		return false;

	this->_charValue = b[0];

	return true;
}

bool Convert::isFloat(void) {
	return false;
}

bool Convert::isDouble(void) {
	return false;
}
