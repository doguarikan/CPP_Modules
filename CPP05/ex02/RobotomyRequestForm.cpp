#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 45, 72), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 45, 72), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const { return this->target; }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if(!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if(executor.getGrade() > this->getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();
    
    std::cout << "* DRILLING NOISES *" << std::endl;
    
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "!" << std::endl;
}
