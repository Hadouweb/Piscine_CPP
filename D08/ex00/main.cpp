#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <map>

int 	main(void) {

	std::list<int> intList;
	intList.push_back(42);
	intList.push_back(4);
	intList.push_back(2);
	std::list<int>::const_iterator ret = easyfind< std::list<int> >(intList, 42);
	std::cout << *ret << std::endl;

	std::vector<int> intVector(3, 42);
	intVector[0] = 35;
	std::vector<int>::const_iterator ret2 = easyfind< std::vector<int> >(intVector, 35);
	std::cout << *ret2 << std::endl;

	return 0;
}