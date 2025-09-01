#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("name"), isSigned(false), gradeToSign(100), gradeToExecute(50) {}

Form::Form(const std::string &name, int gradeSign, int gradeExec) : name(name), isSigned(false), gradeToSign(gradeSign), gradeToExecute(gradeExec) {
    if(gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if(gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute) {}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
    isSigned = true;
}

const std::string &Form::getName() const { return name; }

bool Form::getIsSigned() const { return isSigned; }

int Form::getGradeRequiredToSign() const { return gradeToSign; }

int Form::getGradeRequiredToExecute() const { return gradeToExecute; }

const char *Form::GradeTooLowException::what() const throw() { return "Grade too low!!"; }

const char *Form::GradeTooHighException::what() const throw() { return "Grade too high!!"; }

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form " << form.getName() << " (Required sign grade: " << form.getGradeRequiredToSign() << ", Required exec grade: " 
		<< form.getGradeRequiredToExecute() << ") is " << (form.getIsSigned() ? "signed" : "not signed") << ".";
	return os;
}