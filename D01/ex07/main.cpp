#include "FileManager.hpp"
#include <iostream>

int		main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string s1 = av[2];
		std::string s2 = av[3];

		if (!s1.empty() && !s2.empty()) {
			FileManager fl(av[1]);
			fl.makeNewStr(s1, s2);
			fl.replace();
		}
	}
	else
		std::cout << "Usage : filename, string, string" << std::endl;
	return 0;
}