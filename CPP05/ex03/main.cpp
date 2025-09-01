#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void testInternCreation() {
    std::cout << "---Intern Form Creation Test---" << std::endl;
    try {
        Intern intern;
        
        std::cout << "Creating RobotomyRequestForm:" << std::endl;
        AForm* robotomy = intern.makeForm("robotomy request", "Bender");
        std::cout << "Form created: " << *robotomy << std::endl;
        delete robotomy;
        
        std::cout << "\nCreating ShrubberyCreationForm:" << std::endl;
        AForm* shrubbery = intern.makeForm("shrubbery creation", "home");
        std::cout << "Form created: " << *shrubbery << std::endl;
        delete shrubbery;
        
        std::cout << "\nCreating PresidentialPardonForm:" << std::endl;
        AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << "Form created: " << *pardon << std::endl;
        delete pardon;
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testInternInvalidForm() {
    std::cout << "---Intern Invalid Form Test---" << std::endl;
    try {
        Intern intern;
        
        std::cout << "Trying to create invalid form:" << std::endl;
        intern.makeForm("invalid form type", "target");
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testInternWithBureaucrat() {
    std::cout << "---Intern + Bureaucrat Integration Test---" << std::endl;
    try {
        Intern intern;
        Bureaucrat president("President", 1);
        
        AForm* pardon = intern.makeForm("presidential pardon", "Marvin");
        std::cout << "Form created: " << *pardon << std::endl;
        
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
