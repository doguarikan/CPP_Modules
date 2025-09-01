#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate() {
	int randomNum = std::rand() % 3;

	if (randomNum == 0) {
		std::cout << "Generated: A" << std::endl;
		return new A();
	} else if (randomNum == 1) {
		std::cout << "Generated: B" << std::endl;
		return new B();
	} else {
		std::cout << "Generated: C" << std::endl;
		return new C();
	}
}

void identify(Base* p) {
	if (!p) {
		std::cout << "Pointer is null" << std::endl;
		return;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer identifies: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer identifies: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer identifies: C" << std::endl;
	else
		std::cout << "Pointer identifies: Unknown Type" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference identifies: A" << std::endl;
		return;
	}
	catch (std::exception& e) {  
    	std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference identifies: B" << std::endl;
		return;
	}
	catch (std::exception& e) {  
    	std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference identifies: C" << std::endl;
		return;
	}
	catch (std::exception& e) {  
    	std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "Reference identifies: Unknown Type" << std::endl;
}

int main() {
	std::srand(std::time(0));
	Base* obj = generate();

	identify(obj);
	identify(*obj);

	delete obj;

	return 0;
}
