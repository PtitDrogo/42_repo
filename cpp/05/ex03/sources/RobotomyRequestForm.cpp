#include "RobotomyRequestForm.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other.getTarget()) {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}


RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const {return _target;}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    std::cout << "Brrrrrrr! Brrrrr! Vrrrrrrrr! Oh man its bleeding everywhere... VRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2 == 0)
        std::cout << "Dear " << _target  << ", you have been robotomized." << std::endl;
    else
        std::cout << "Dear " << _target  << ", you have not been robotomized and I am not liable for brain damage." << std::endl;
    std::cout << executor.getName() << " executed form " << (*this).getName() << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other.getTarget();
    }
    return (*this);
}

std::ostream    &operator<<(std::ostream &out, RobotomyRequestForm const &RobotomyRequestForm)
{
    out << static_cast<const AForm&>(RobotomyRequestForm);
    out << ", Target is " << RobotomyRequestForm.getTarget();
    return (out);
}