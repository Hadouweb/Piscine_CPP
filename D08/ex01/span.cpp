#include "span.hpp"

Span::Span(void) : _maxLen(0) {

}


Span::Span(Span const &src) {
	*this = src;
}

Span::~Span(void) {
	this->_data.clear();
}

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		this->_maxLen = rhs._maxLen;
		this->_data = rhs._data;
	}
	return *this;
}

Span::Span(unsigned int pMaxLen) : _maxLen(pMaxLen) {

}

unsigned int Span::getLen(void) const {
	return this->_maxLen;
}

void Span::addNumber(int n) {
	if (this->_data.size() == this->getLen())
		throw std::out_of_range("out of limit.");
	else {
		this->_data.push_back(n);
	}
}

int Span::shortestSpan(void) const {
	return (*std::max_element(this->_data.begin(), this->_data.end()) -
			*std::min_element(this->_data.begin(), this->_data.end()));
}

int Span::longestSpan(void) const {
	if (this->_data.size() > 1) {
		std::vector<int> tmp;
		tmp = this->_data;
		std::sort(tmp.begin(), tmp.end());
		int ret = tmp[1] - tmp[0];
		tmp.clear();
		return ret;
	} else
		throw std::exception("longestSpan not found.");
	return -1;
}
