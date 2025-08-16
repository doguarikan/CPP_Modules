#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    if (this != &other) {
        // Intern has no attributes to copy
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string lowerFormName = formName;
    
    for (size_t i = 0; i < lowerFormName.length(); i++)
        lowerFormName[i] = std::tolower(lowerFormName[i]);
    
    if (lowerFormName == "shrubbery creation" || lowerFormName == "shrubberycreationform") {
        std::cout << "Intern creates " << formName << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if (lowerFormName == "robotomy request" || lowerFormName == "robotomyrequestform") {
        std::cout << "Intern creates " << formName << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (lowerFormName == "presidential pardon" || lowerFormName == "presidentialpardonform") {
        std::cout << "Intern creates " << formName << std::endl;
        return new PresidentialPardonForm(target);
    }
    else
        throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() { return "Form not found!!"; }
