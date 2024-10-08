#include "PresidentialPardonForm.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other.getTarget()) {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}


PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const {return _target;}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other.getTarget();
    }
    return (*this);
}

std::ostream    &operator<<(std::ostream &out, PresidentialPardonForm const &PresidentialPardonForm)
{
    out << static_cast<const AForm&>(PresidentialPardonForm);
    out << ", type of form : PresidentialPardon, target is " << PresidentialPardonForm.getTarget();
    return (out);
}
void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
    std::cout << "hi guys this is my parameter bureaucrat" << executor << std::endl;
}