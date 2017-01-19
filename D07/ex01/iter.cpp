#include <iostream>

template<typename T>
void printCell(T c) {
	std::cout << c << std::endl;
}

template<typename T>
void mult(T c) {
	std::cout << (c * c) << std::endl;
}

template<typename A, typename S, typename F>
void iter(A *ptr, S size, F f) {
	for (int i = 0; i < size; i++) {
		f(ptr[i]);
	}
}

int 	main(void) {
	std::string buffString[3] = {"coucou", "lol", "hey"};
	std::cout << "[std::string buffString[3] = {\"coucou\", \"lol\", \"hey\"};] =" << std::endl;
	iter<std::string, int, void(*)(std::string &)>(buffString, 3, &printCell);

	std::cout << std::endl;

	char buffChar[4] = {'a', 'b', '1', 42};
	std::cout << "[char buffChar[4] = {'a', 'b', '1', 42};] =" << std::endl;
	iter<char, int, void(*)(char &)>(buffChar, 4, &printCell);

	std::cout << std::endl;

	float buffFloat[2] = {3.3, 2.2};
	std::cout << "[float buffFloat[3] = {3.3, 2};] =" << std::endl;
	iter<float, int, void(*)(float &)>(buffFloat, 2, &printCell);

	std::cout << std::endl;

	int buffInt[2] = {3, 2};
	std::cout << "[int buffInt[2] = {3, 2};] =" << std::endl;
	iter<int, int, void(*)(int &)>(buffInt, 2, &printCell);
	iter<int, int, void(*)(int &)>(buffInt, 2, &mult);

	return 0;
}