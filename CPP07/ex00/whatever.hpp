#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T & one, T & two) {
	T temp = one;
	one = two;
	two = temp;
}

template <typename T>
T const & min(T const & one, T const & two) {
	return (two < one) ? two : one;
}

template <typename T>
T const & max(T const & one, T const & two) {
	return (two > one) ? two : one;
}

#endif

