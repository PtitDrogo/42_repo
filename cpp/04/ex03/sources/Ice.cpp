#include "Ice.h"
#include <iostream>

// There seem to be a need for deep copy but i am not sure what the hell
// requires copying;

Ice::Ice() : AMateria("ice") {}
Ice::Ice(Ice const & other) : AMateria(other.getType()) {}
Ice::~Ice() 
{
    std::cout << "whats up gang Ice Destroyer here" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        // Do nothing I guess !
    }
    return (*this);
}

std::string const &Ice::getType() const { return type; }

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
Ice *Ice::clone() const
{
    Ice *new_Ice = new Ice(*this);
    return (new_Ice);
}

std::ostream    &operator<<(std::ostream &out, Ice const &fixed)
{
    out << "Materia : " << fixed.getType();
    return (out);
}