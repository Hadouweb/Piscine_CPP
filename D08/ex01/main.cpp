#include "span.hpp"
#include <vector>

int main()
{
	Span sp = Span(5);

	try {
		sp.addNumber(5);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp.addNumber(3);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp.addNumber(17);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp.addNumber(9);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp.addNumber(11);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	Span sp2 = Span(1);

	try {
		sp2.addNumber(42);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp2.addNumber(35);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << sp2.shortestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << sp2.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	Span sp3 = Span(10000);
	srand(time(NULL));

	for (unsigned int i = 0; i < sp3.getLen(); i++) {
		sp3.addNumber(rand());
	}

	try {
		std::cout << sp3.shortestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << sp3.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		sp3.addNumber(42);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}