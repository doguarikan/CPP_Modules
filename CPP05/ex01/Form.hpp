#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    
    public:
        Form ();
        Form(const std::string &name, int gradeExec, int gradeSign);
        Form(const Form &other);
	    Form &operator=(const Form &other);
        ~Form();

        const std::string &getName() const;
        bool getIsSigned() const;
        int getGradeRequiredToSign() const;
        int getGradeRequiredToExecute() const;
        
        void beSigned(const Bureaucrat &bureaucrat);
        
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif