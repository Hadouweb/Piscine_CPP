#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
public:
    Span(void);
    Span(unsigned int pMaxLen);
    Span(Span const & src);

    ~Span(void);

    Span & operator=(Span const & rhs);

	void addNumber(int n);
	unsigned int getLen(void) const;

	int shortestSpan(void) const;
	int longestSpan(void) const;

private:
	unsigned int _maxLen;
	std::vector<int> _data;
};

#endif