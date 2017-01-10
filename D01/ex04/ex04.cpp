#include <iostream>

int 	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr_str = &str;
	std::string &ref_str = str;

	std::cout << *ptr_str << std::endl;
	std::cout << ref_str << std::endl;
	return 0;
}