#include <exception>

template <typename T>
Array<T>::Array() : data(0), len(0) {}

template <typename T>
Array<T>::Array(size_t n) : len(n) { data = new T[n](); }

template <typename T>
Array<T>::Array(const Array& other) : len(other.len) {
	data = new T[len];
	for (size_t i = 0; i < len; ++i)
		data[i] = other.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other) {
		delete[] data;
		len = other.len;
		data = new T[len];
		for (size_t i = 0; i < len; ++i)
			data[i] = other.data[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() { delete[] data; }

template <typename T>
size_t Array<T>::size() const { return len; }

template <typename T>
T& Array<T>::operator[](size_t index) {
	if (index >= len)
		throw std::out_of_range("Out of bounds");
	return data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= len)
		throw std::out_of_range("Out of bounds");
	return data[index];
}
