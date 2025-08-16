#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
    std::string target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
        
        std::string getTarget() const;

        virtual void execute(Bureaucrat const &executor) const;
};

#endif
