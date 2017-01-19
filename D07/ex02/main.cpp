#include <iostream>
#include "Array.hpp"

int 	main(void) {

	Array<int> intTest1;
	Array<int> intTest2(42);

	std::cout << "(Init : Array<int> intTest1)" << std::endl;
	std::cout << "(Init : Array<int> intTest2(42))" << std::endl;

	std::cout << std::endl;

	try {
		std::cout << "(try : print intTest1[0]) = ";
		std::cout << intTest1[0] << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "(try : intTest2[3] = 312312)";
		intTest2[3] = 312312;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "(try : print intTest2[3]) = ";
		std::cout << intTest2[3] << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<int> intTestCopy(intTest2);
	std::cout << "(Init : Array<int> intTestCopy(intTest2)" << std::endl;
	try {
		std::cout << "(try : print intTestCopy[3]) = ";
		std::cout << intTestCopy[3] << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<float> floatTest1(3);
	std::cout << "(Init : Array<float> floatTest1(3)" << std::endl;
	try {
		std::cout << "(try : floatTest1[3] = 42.2) = ";
		floatTest1[3] = 42.2;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "(try : floatTest1[2] = 42.2)";
		floatTest1[2] = 42.2;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "(try : print floatTest1[2]) = ";
		std::cout << floatTest1[2] << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array< Array<int> > int2d(2);
	std::cout << "(Init : Array<Array<int>> intPtr(2)" << std::endl;
	try {
		std::cout << "(try : int2d[0] = intTest2) ";
		int2d[0] = intTest2;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "(try : int2d[0][35] = 42) ";
		int2d[0][35] = 42;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "(try : print for int2d[0][i]) : " << std::endl;
		unsigned int len = int2d[0].getLen();
		for (unsigned int i = 0; i < len; i++) {
			std::cout << int2d[0][i] << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<std::string> stringTest1(3);
	std::cout << "(Init : Array<std::string> stringTest1(3)" << std::endl;
	try {
		std::cout << "(try : stringTest1[1] = \"Hello World\")";
		stringTest1[1] = "Hello World";
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "(try : print stringTest1[1]) = ";
		std::cout << stringTest1[1] << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}