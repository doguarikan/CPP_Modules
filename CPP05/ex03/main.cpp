#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void testInternCreation() {
    std::cout << "=== Intern Form Creation Test ===" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* rrf;
        
        std::cout << "Creating RobotomyRequestForm:" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << "Form created: " << *rrf << std::endl;
        delete rrf;
        
        std::cout << "\nCreating ShrubberyCreationForm:" << std::endl;
        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        std::cout << "Form created: " << *shrubbery << std::endl;
        delete shrubbery;
        
        std::cout << "\nCreating PresidentialPardonForm:" << std::endl;
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << "Form created: " << *pardon << std::endl;
        delete pardon;
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testInternInvalidForm() {
    std::cout << "=== Intern Invalid Form Test ===" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* invalidForm;
        
        std::cout << "Trying to create invalid form:" << std::endl;
        invalidForm = someRandomIntern.makeForm("invalid form", "target");
        
    } catch (const std::exception& e) {
        std::cout << "Expected exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testInternWithBureaucrat() {
    std::cout << "=== Intern + Bureaucrat Integration Test ===" << std::endl;
    try {
        Intern someRandomIntern;
        Bureaucrat president("President", 1);
        
        // Create form using intern
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");
        std::cout << "Form created: " << *pardon << std::endl;
        
        // Sign and execute with bureaucrat
        president.signForm(*pardon);
        president.executeForm(*pardon);
        
        delete pardon;
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    testInternCreation();
    testInternInvalidForm();
    testInternWithBureaucrat();
    
    return 0;
}
