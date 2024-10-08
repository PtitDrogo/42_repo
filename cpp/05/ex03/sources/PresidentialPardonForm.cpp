#include "PresidentialPardonForm.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other.getTarget()) {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}


PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const {return _target;}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    std::cout << "Dear " << _target  << ", you have been pardoned by Zaphod Beeblebrox." << std::endl;
    std::cout << executor.getName() << " executed form " << (*this).getName() << std::endl;
}
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
    out << ", Target is " << PresidentialPardonForm.getTarget();
    return (out);
}