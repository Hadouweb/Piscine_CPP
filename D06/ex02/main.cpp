#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int i = rand() % 3;
	Base *b;

	if (i == 0)
		b = new A();
	else if (i == 1)
		b = new B();
	else
		b = new C();

	return b;
}

void identify_from_pointer(Base * p) {
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);

	if (a)
		std::cout << 'A' << std::endl;
	else if (b)
		std::cout << 'B' << std::endl;
	else if (c)
		std::cout << 'C' << std::endl;
}

void identify_from_reference(Base & p) {
	try {
		A & a = dynamic_cast<A &>(p);
		if (&a + 1)
			;
		std::cout << 'A' << std::endl;
	} catch (std::bad_cast & e) {
		;//std::cout << e.what() << std::endl;
	}
	try {
		B & b = dynamic_cast<B &>(p);
		if (&b + 1)
			;
		std::cout << 'B' << std::endl;
	} catch (std::bad_cast & e) {
		;//std::cout << e.what() << std::endl;
	}
	try {
		C & c = dynamic_cast<C &>(p);
		if (&c + 1)
			;
		std::cout << 'C' << std::endl;
	} catch (std::bad_cast & e) {
		;//std::cout << e.what() << std::endl;
	}
}

int 	main(void) {
	srand(time(NULL));

	Base *b = generate();

	std::cout << "identify_from_pointer : ";
	identify_from_pointer(b);

	std::cout << "identify_from_reference : ";
	identify_from_reference(*b);

	return 0;
}