#include "Bureaucrat.hpp"

int main() {
	try {

		Bureaucrat bur1("LeBron", 2);
		std::cout << bur1 << std::endl;
		bur1.incrementGrade();
		std::cout << bur1 << std::endl;

		Bureaucrat bur2("Wade", 150);
		std::cout << bur2 << std::endl;
		bur2.decrementGrade(); 
		std::cout << bur2 << std::endl;

    } catch (std::exception &e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur4("Bosh", 1);
		std::cout << bur4 << std::endl;
		bur4.incrementGrade();
		std::cout << bur4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}
	
	return 0;
}
