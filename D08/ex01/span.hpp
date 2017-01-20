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
	void addNumber(int nbElem, int value);
	void addNumber(int nbElem, int (*f)(void));
	unsigned int getLen(void) const;

	int shortestSpan(void) const;
	int longestSpan(void) const;

	class ShortestSpanException : public std::exception {
		public:
			ShortestSpanException(void);
			~ShortestSpanException(void) throw();
			ShortestSpanException(ShortestSpanException const & src);
			virtual const char* what() const throw();
		private:
			ShortestSpanException & operator=(ShortestSpanException const & rhs);
	};

	class LongestSpanException : public std::exception {
		public:
			LongestSpanException(void);
			~LongestSpanException(void) throw();
			LongestSpanException(LongestSpanException const & src);
			virtual const char* what() const throw();
		private:
			LongestSpanException & operator=(LongestSpanException const & rhs);
	};

private:
	unsigned int _maxLen;
	std::vector<int> _data;
};

#endif