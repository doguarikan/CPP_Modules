#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat  {
    std::string name;
    int grade;
    public:
        Bureaucrat (const std::string &name, int grade);
	    ~Bureaucrat ();
        std::string getName() const;
        int getGrade() const;
    
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
