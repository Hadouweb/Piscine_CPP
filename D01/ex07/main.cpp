#include "FileManager.hpp"
#include <iostream>

int		main(int ac, char **av)
{
	if (ac == 4)
	{
		std::fstream fs;
		if (FileManager::fileExist(av[1]))
			fs.open (av[1], std::fstream::out | std::fstream::in);
		else {
			fs.open(av[1], std::fstream::out);
			fs.close();
			fs.open (av[1], std::fstream::out | std::fstream::in);
		}

		std::string s1 = av[2];
		std::string s2 = av[3];
		if (!s1.empty() && !s2.empty())
		{
			FileManager fl(fs);
			fl.makeNewStr(s1, s2);
			fl.replace();
		}
		fs.close();
	}
	else
		std::cout << "Usage : filename, string, string" << std::endl;
	return 0;
}