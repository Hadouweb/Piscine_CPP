#include "FileManager.hpp"

FileManager::FileManager(std::fstream& pFile) : _file(pFile) {
	std::string line;
	while (std::getline(this->_file, line))
		this->_newStr += line;
	this->_file.clear();
	this->_file.seekg(0);
}

FileManager::~FileManager() {

}

void FileManager::replace(void) {
	this->_file << this->_newStr;
}

void FileManager::makeNewStr(std::string s1, std::string s2) {
	size_t start_pos = 0;
	while((start_pos = this->_newStr.find(s1, start_pos)) != std::string::npos) {
		this->_newStr.replace(start_pos, s1.length(), s2);
		start_pos += s2.length(); // ...
	}
}

bool FileManager::fileExist(const std::string& filename) {
	std::ifstream ifile(filename);
	return ifile;
}