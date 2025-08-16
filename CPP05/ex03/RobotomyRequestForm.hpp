#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
    std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
        
        std::string getTarget() const;

        virtual void execute(Bureaucrat const &executor) const;
};

#endif
