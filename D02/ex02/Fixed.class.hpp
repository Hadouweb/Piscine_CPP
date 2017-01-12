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

    bool operator>(Fixed const & rhs);
    bool operator<(Fixed const & rhs);
    bool operator>=(Fixed const & rhs);
    bool operator<=(Fixed const & rhs);
    bool operator==(Fixed const & rhs);
    bool operator!=(Fixed const & rhs);

	Fixed  operator+(Fixed const & rhs);
	Fixed  operator-(Fixed const & rhs);
	Fixed  operator*(Fixed const & rhs);
	Fixed  operator/(Fixed const & rhs);
	Fixed & operator++(void);
	Fixed & operator--(void);
	Fixed  operator++(int);
	Fixed  operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	static Fixed & max(Fixed & lhs, Fixed  & rhs);
	static Fixed & min(Fixed & lhs, Fixed  & rhs);
	static const Fixed & max(Fixed const & lhs, Fixed const & rhs);
	static const Fixed & min(Fixed const & lhs, Fixed const & rhs);

private:
	int _fixed;
	static const int _bits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & f);

#endif