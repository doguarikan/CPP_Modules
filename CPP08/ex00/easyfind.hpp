#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
int easyfind(T& cont, int num) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), num);
	if (it == cont.end())
		return -1;
	return *it;
}

#endif
