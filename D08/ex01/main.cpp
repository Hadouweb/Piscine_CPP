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

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	/*for(std::vector<int>::iterator it = sp._data.begin(); it != sp._data.end(); ++it) {
		std::cout << *it << std::endl;
	}*/
}