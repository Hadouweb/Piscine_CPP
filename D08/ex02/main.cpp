#include "mutantstack.hpp"
#include <iostream>
#include <deque>
#include <stack>
#include <list>

int 	main(void) {

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	MutantStack<float> fstack;
	fstack.push(34.5);
	fstack.push(42.5);
	fstack.push(.9);
	MutantStack<float>::iterator it2 = fstack.begin();

	while (it2 != fstack.end())
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	return 0;
}