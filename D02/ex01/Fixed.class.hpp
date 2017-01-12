#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
    Fixed(void);
	Fixed(int const value);
	Fixed(float const value);
    Fixed(Fixed const & src);
    ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fpv;
	static const int _fract;
};

std::ostream & operator<<(std::ostream & o, Fixed const & f);

#endif