#ifndef FILE_MANAGER_HPP
# define FILE_MANAGER_HPP

#include <fstream>
#include <iostream>

class FileManager {
public:
	FileManager(std::fstream& pFile);
	~FileManager(void);

	void makeNewStr(std::string s1, std::string s2);
	static bool fileExist(const std::string& filename);
	void replace(void);

private:
	std::fstream& _file;
	std::string _newStr;
};

#endif