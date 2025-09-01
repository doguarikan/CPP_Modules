#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 137, 145), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 137, 145), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const { return this->target; }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if(!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if(executor.getGrade() > this->getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();
    
    std::string fname = this->target + "_shrubbery";
    std::ofstream outfile(fname.c_str());
    
    if(!outfile.is_open())
        throw FileOpenException();
        
    const int width = 29;
    for (int i = 1; i <= width; i += 2)
        outfile << std::string((width - i) / 2, ' ') << std::string(i, '*') << std::endl;

    for (int i = 0; i < width / 5; ++i)
        outfile << std::string((width - 3) / 2, ' ') << "|||" << std::endl;

    outfile.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() { return "Could not open file for writing!!"; }
