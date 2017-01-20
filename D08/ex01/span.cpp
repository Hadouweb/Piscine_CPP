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
	if (this->_data.size() > 1) {
		return (*std::max_element(this->_data.begin(), this->_data.end()) -
				*std::min_element(this->_data.begin(), this->_data.end()));
	} else
		throw Span::LongestSpanException();
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
		throw Span::ShortestSpanException();
}

Span::ShortestSpanException::ShortestSpanException(void) { }

Span::ShortestSpanException::~ShortestSpanException(void) throw() { }

Span::ShortestSpanException::ShortestSpanException(
		const Span::ShortestSpanException &src) {
	*this = src;
}

Span::ShortestSpanException &
Span::ShortestSpanException::operator=(const Span::ShortestSpanException &rhs) {
	if (this != &rhs) { }
	return *this;
}

const char *Span::ShortestSpanException::what() const throw() {
	return "ShortestSpanException: not possible.";
}

Span::LongestSpanException::LongestSpanException(void) { }

Span::LongestSpanException::~LongestSpanException(void) throw() { }

Span::LongestSpanException::LongestSpanException(
		const Span::LongestSpanException &src) {
	*this = src;
}

Span::LongestSpanException &
Span::LongestSpanException::operator=(const Span::LongestSpanException &rhs) {
	if (this != &rhs) { }
	return *this;
}

const char *Span::LongestSpanException::what() const throw() {
	return "LongestSpanException: not possible.";
}