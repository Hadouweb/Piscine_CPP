#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(char p1, char p2) : a1(p1), a2(p2) {
	std::cout << "Constructor" << std::endl;
	std::cout << this->a1 << " " << this->a2 << std::endl;
	return;
}

Sample::~Sample(void) {
	std::cout << "Destructor" << std::endl;
	return; 
}

int Sample::f(void) const {
	return this->foo + 1;
}