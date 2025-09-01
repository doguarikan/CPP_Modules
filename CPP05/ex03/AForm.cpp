#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("name"), isSigned(false), gradeToSign(100), gradeToExecute(50) {}

AForm::AForm(const std::string &name, int gradeExec, int gradeSign) : name(name), isSigned(false), gradeToSign(gradeSign), gradeToExecute(gradeExec) {
    if(gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if(gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
    isSigned = true;
}

const std::string &AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getGradeRequiredToSign() const { return gradeToSign; }

int AForm::getGradeRequiredToExecute() const { return gradeToExecute; }

const char *AForm::GradeTooLowException::what() const throw() { return "Grade too low!!"; }

const char *AForm::GradeTooHighException::what() const throw() { return "Grade too high!!"; }

const char *AForm::FormNotSignedException::what() const throw() { return "Form is not signed!!"; }

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "Form " << form.getName() << " (Required sign grade: " << form.getGradeRequiredToSign()
	   << ", Required exec grade: " << form.getGradeRequiredToExecute()
	   << ") is " << (form.getIsSigned() ? "signed" : "not signed") << ".";
	return os;
}
