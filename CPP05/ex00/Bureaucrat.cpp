#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) {
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    this->name = name;
    this->grade = grade;
}

Bureaucrat::~Bureaucrat () {}

std::string Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

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

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade Too Low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade Too High!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}