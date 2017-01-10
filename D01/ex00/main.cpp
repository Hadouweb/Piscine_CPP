#include "Pony.hpp"
#include <iostream>

Pony* ponyOnTheHeap(void) {
	Pony *p = new Pony("PonyHeap");
	return p;
}

void ponyOnTheStack(void) {
	Pony p = Pony("PonyStack");
	p = p;
}

int 	main(void) {
	Pony *p = ponyOnTheHeap();
	ponyOnTheStack();

	std::cout << "Using delete in main function" << std::endl;
	delete p;

	return 0;
}