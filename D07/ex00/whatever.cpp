#include <iostream>

template<typename T>
void swap(T & lhs, T & rhs) {
	T tmp(lhs);
	lhs = rhs;
	rhs = tmp;
}

template<typename T>
T & min(T & lhs, T & rhs) {
	return (lhs < rhs ? lhs : rhs);
}

template<typename T>
T & max(T & lhs, T & rhs) {
	return (lhs > rhs ? lhs : rhs);
}

int 	main(void) {

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl;

	float af = 0.42;
	float bf = 42.0;
	std::cout << "af = " << af << ", bf = " << bf << std::endl;
	std::cout << "min( af, bf ) = " << ::min( af, bf ) << std::endl;
	std::cout << "max( af, bf ) = " << ::max( af, bf ) << std::endl;

	std::cout << std::endl;

	void * aPtr = &af;
	void * bPtr = &bf;
	std::cout << "aPtr = " << aPtr << ", bPtr = " << bPtr << std::endl;
	std::cout << "min( aPtr, bPtr ) = " << ::min( aPtr, bPtr ) << std::endl;
	std::cout << "max( aPtr, bPtr ) = " << ::max( aPtr, bPtr ) << std::endl;

	return 0;
}