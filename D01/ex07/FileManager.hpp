#ifndef FILE_MANAGER_HPP
# define FILE_MANAGER_HPP

#include <fstream>
#include <iostream>

class FileManager {
public:
	FileManager(std::string pFileName);
	~FileManager(void);

	void makeNewStr(std::string s1, std::string s2);
	void replace(void);

private:
	std::string _fileName;
	std::string _newStr;
};

#endif