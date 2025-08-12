#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;

		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;
		b2.decrementGrade(); 
		std::cout << b2 << std::endl;

		Bureaucrat b4("Tom", 1);
		std::cout << b4 << std::endl;
		b4.incrementGrade();
		std::cout << b4 << std::endl;
    }
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}