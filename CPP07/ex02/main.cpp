#include <iostream>
#include "Array.hpp"

int main() {
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;

	Array<int> nums(5);
	for (unsigned int i = 0; i < nums.size(); ++i) {
		nums[i] = static_cast<int>(i) * 10;
	}
	for (unsigned int i = 0; i < nums.size(); ++i) {
		std::cout << nums[i] << (i + 1 == nums.size() ? '\n' : ' ');
	}

	Array<int> copy(nums);
	copy[0] = 999;
	std::cout << "nums[0]=" << nums[0] << ", copy[0]=" << copy[0] << std::endl;

	try {
		std::cout << nums[10] << std::endl;
	} catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

