#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testShrubberyCreationForm() {
    std::cout << "=== ShrubberyCreationForm Test ===" << std::endl;
    try {
        Bureaucrat high("High", 1);
        Bureaucrat low("Low", 150);
        
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;
        
        // Try to execute unsigned form
        try {
            high.executeForm(shrubbery);
        } catch (const std::exception& e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }
        
        // Sign and execute
        high.signForm(shrubbery);
        high.executeForm(shrubbery);
        
        // Try with low grade
        ShrubberyCreationForm shrubbery2("garden");
        try {
            low.signForm(shrubbery2);
        } catch (const std::exception& e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testRobotomyRequestForm() {
    std::cout << "=== RobotomyRequestForm Test ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        RobotomyRequestForm robotomy("Bender");
        
        std::cout << robotomy << std::endl;
        
        president.signForm(robotomy);
        
        // Try multiple times to see random success/failure
        for (int i = 0; i < 5; i++) {
            president.executeForm(robotomy);
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testPresidentialPardonForm() {
    std::cout << "=== PresidentialPardonForm Test ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        Bureaucrat intern("Intern", 150);
        
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        
        // Try with insufficient grade
        try {
            intern.signForm(pardon);
        } catch (const std::exception& e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }
        
        // Sign and execute with president
        president.signForm(pardon);
        president.executeForm(pardon);
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    
    return 0;
}
