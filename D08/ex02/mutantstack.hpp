#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T>() { }
	MutantStack(MutantStack const & src) : std::stack<T>(src) { }
	~MutantStack() { }

	MutantStack	& operator=(MutantStack &rhs) {
		if (this != &rhs) {
		}
		return *this;
	}

	typedef typename std::deque<T>::iterator iterator;

	typename std::deque<T>::iterator begin() {
		return this->c.begin();
	}

	typename std::deque<T>::iterator end() {
		return this->c.end();
	}
};

#endif