#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testShrubberyCreationForm() {
    std::cout << "---ShrubberyCreationForm---" << std::endl;

    try {
        Bureaucrat king("King", 1);
        Bureaucrat clown("Clown", 150);
        
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;
        
        try {
            king.executeForm(shrubbery);
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        
        king.signForm(shrubbery);
        king.executeForm(shrubbery);
        
        ShrubberyCreationForm shrubbery2("garden");
        try {
            clown.signForm(shrubbery2);
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void testRobotomyRequestForm() {
    std::cout << "---RobotomyRequestForm---" << std::endl;
    try {
        Bureaucrat ceo("Ceo", 1);
        RobotomyRequestForm walle("Wall-e");
        
        std::cout << walle << std::endl;
        
        ceo.signForm(walle);
        
        for (int i = 0; i < 3; i++)
            ceo.executeForm(walle);
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testPresidentialPardonForm() {
    std::cout << "---PresidentialPardonForm---" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        
        try {
            intern.signForm(pardon);
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        
        boss.signForm(pardon);
        boss.executeForm(pardon);
        
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
