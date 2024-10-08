#ifndef PDF_H
# define PDF_H

#include <iostream>
#include "Bureaucrat.h"
#include "AForm.h"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
    //We dont want to call the default constructor;
    PresidentialPardonForm();

public:
    //Constructors
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm(std::string target);
    
    //Destructors
    ~PresidentialPardonForm();

    //methods 
    void execute(Bureaucrat const & executor) const;

    //getters
    std::string getTarget() const;
    //Overloads
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};

std::ostream    &operator<<(std::ostream &o, PresidentialPardonForm const &fixed);
#endif