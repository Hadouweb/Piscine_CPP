#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <deque>
#include <stack>

template <typename T>
class MutantStack  {
public:
    MutantStack<T>(void);
    MutantStack<T>(MutantStack<T> const & src);

    ~MutantStack<T>(void);

    MutantStack<T> & operator=(MutantStack<T> const & rhs);

	void push(int v) {
		this->_stack.push_back(v);
	}

	void pop(void) {
		this->_stack.pop_back();
	}

	int top(void) const {
		return this->_stack.back();
	}

	MutantStack::iterator begin();
	MutantStack::iterator end();

	template <typename U>
	class iterator {
		public:
		    iterator<U>(void);
		    iterator<U>(iterator<U> const & src);

		    ~iterator<U>(void);

		    iterator<U> & operator=(iterator<U> const & rhs);
			iterator<U> & operator++(void);
			iterator<U> & operator--(void);
			iterator<U>  operator++(int);
			iterator<U>  operator--(int);

		private:
			unsigned int _it;
			MutantStack<T> _value;
	};

private:
	std::deque<T> _stack;
};

#endif