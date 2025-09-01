#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdexcept>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

static AForm* createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    const std::string FormTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*FormCreators[3])(const std::string &) = {&createShrubbery, &createRobotomy, &createPresidentialPardon};

	for (int i = 0; i < 3; i++)
		if (formName == FormTypes[i])
		{
			std::cout << "Intern creates: " << formName << std::endl;
			return FormCreators[i](target);
		}

	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() { return "Form not found!!"; }
