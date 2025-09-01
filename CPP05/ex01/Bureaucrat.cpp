#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat () : name("name"), grade(100) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat () {}

std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incrementGrade() {
    if(grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if(grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low!!"; }

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high!!"; }

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}