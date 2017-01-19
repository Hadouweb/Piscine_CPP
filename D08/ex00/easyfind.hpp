#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <list>
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(T const & a, int b) {
	return std::find(a.begin(), a.end(), b);
}

#endif