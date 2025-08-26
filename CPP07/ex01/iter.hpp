#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename Function>
void iter(T *arr, size_t len, Function fun) {
	if (arr == 0)
		return;
	for (size_t i = 0; i < len; ++i)
		fun(arr[i]);
}

#endif

