#include "FileManager.hpp"

FileManager::FileManager(std::string pFileName) : _fileName(pFileName) {
	std::ifstream ifs(pFileName);
	if (ifs)
	{
		std::string line;
		while (std::getline(ifs, line))
			this->_newStr += line;
		ifs.close();
	}
}

FileManager::~FileManager() {

}

void FileManager::replace(void) {
	if (!this->_newStr.empty()) {
		for (int i = 0; this->_fileName[i]; i++)
			this->_fileName[i] = toupper(this->_fileName[i]);
		std::ofstream ofs(this->_fileName + ".replace");
		if (ofs) {
			ofs << this->_newStr;
		}
		ofs.close();
	}
}

void FileManager::makeNewStr(std::string s1, std::string s2) {
	size_t start_pos = 0;
	while((start_pos = this->_newStr.find(s1, start_pos)) != std::string::npos) {
		this->_newStr.replace(start_pos, s1.length(), s2);
		start_pos += s2.length();
	}
}