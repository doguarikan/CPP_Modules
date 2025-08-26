#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T const & element) {
	std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T & element) {
	element++;
}

int main() {
	int num[5] = {1, 2, 3, 4, 5};
	::iter(num, 5, printElement<int>);
	::iter(num, 5, incrementElement<int>);
	::iter(num, 5, printElement<int>);

	std::cout << std::endl;

	const int constnum[3] = {10, 20, 30};
	::iter(constnum, 3, printElement<int>);

	std::cout << std::endl;

	const char * lineup[3] = {"Ronaldo", "Benzema", "Bale"};
	::iter(lineup, 3, printElement<const char *>);

	std::cout << std::endl;

	std::string name[2] = {"Cristiano", "Ronaldo"};
	::iter(name, 2, printElement<std::string>);

	std::cout << std::endl;

	char title[4] = {'G', 'O', 'A', 'T'};
	::iter(title, 4, printElement<char>);

	return 0;
}
