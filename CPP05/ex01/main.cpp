#include "Bureaucrat.hpp"
#include "Form.hpp"

void testFormConstruction() {
	std::cout << "---Form Construction---" << std::endl;

	try {
		std::cout << "Valid grades:" << std::endl;
		Form valid("Contract", 75, 50);
		std::cout << valid << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	try {
		std::cout << "\nToo high grade:" << std::endl;
		Form high("high", 0, 50);
		std::cout << high << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	try {
		std::cout << "\nToo low grade:" << std::endl;
		Form low("low", 75, 151);
		std::cout << low << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testFormSigning() {
	std::cout << "\n---Form Signing---" << std::endl;
	try {
		Bureaucrat king("King", 1);
		Bureaucrat clown("Clown", 150);
		Form form("Important", 50, 25);

		std::cout << "\nForm before signing:" << std::endl;
		std::cout << form << std::endl;
		
		std::cout << "\nSign Clown:" << std::endl;
		clown.signForm(form);

		std::cout << "\nForm after signing Clown:" << std::endl;
		std::cout << form << std::endl;
		
		std::cout << "\nSign King:" << std::endl;
		king.signForm(form);
		
		std::cout << "\nForm after signing King:" << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main() {
	testFormConstruction();
	testFormSigning();
	return 0;
}