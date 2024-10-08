#ifndef RRF_H
# define RRF_H

#include <iostream>
#include "Bureaucrat.h"
#include "AForm.h"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
    //We dont want to call the default constructor;
    RobotomyRequestForm();

public:
    //Constructors
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm(std::string target);
    
    //Destructors
    ~RobotomyRequestForm();

    //methods 
    void execute(Bureaucrat const & executor) const;

    //getters
    std::string getTarget() const;
    //Overloads
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};

std::ostream    &operator<<(std::ostream &o, RobotomyRequestForm const &fixed);
#endif