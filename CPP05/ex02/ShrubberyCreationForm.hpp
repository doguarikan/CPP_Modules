#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
    std::string target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
        
        std::string getTarget() const;

        virtual void execute(Bureaucrat const &executor) const;

        class FileOpenException : public std::exception {
            virtual const char* what() const throw();
        };
};

#endif