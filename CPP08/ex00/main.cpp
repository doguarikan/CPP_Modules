#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
	std::vector<int> vect(10);
	for (int i = 1; i < 10; i++)
		vect.push_back(i * 10);

	std::list<int> lis(10);
	for (int i = 1; i < 10; i++)
		lis.push_back(i);

	std::cout << "Trying to find 30 in vector: " << easyfind(vect, 30) << std::endl;
	std::cout << "Trying to find 5 in list: " << easyfind(lis, 5) << std::endl;
	std::cout << "Trying to find 15 in vector: " << easyfind(vect, 15) << std::endl;
	std::cout << "Trying to find 25 in list: " << easyfind(lis, 25) << std::endl;
	
	return 0;
}