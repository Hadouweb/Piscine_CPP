#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <climits>

class Convert {
public:
	Convert(std::string pBase);
    Convert(Convert const & src);

    ~Convert(void);

    Convert & operator=(Convert const & rhs);

    std::string getBase(void) const;

    bool isChar(void);
    bool isInteger(void);
    bool isFloat(void);
    bool isDouble(void);

private:
	Convert(void);
	std::string _base;
	char _charValue;
	int _intValue;
	float _floatValue;
	double _doubleValue;
};

#endif