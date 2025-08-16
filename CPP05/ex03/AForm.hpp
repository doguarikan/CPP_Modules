#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    
    public:
        AForm(const std::string &name, int gradeExec, int gradeSign);
        AForm(const AForm &other);
	    AForm &operator=(const AForm &other);
        virtual ~AForm();

        const std::string &getName() const;
        bool getIsSigned() const;
        int getGradeRequiredToSign() const;
        int getGradeRequiredToExecute() const;
        
        void beSigned(const Bureaucrat &bureaucrat);

	    virtual void execute(const Bureaucrat &executor) const = 0;
        
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
