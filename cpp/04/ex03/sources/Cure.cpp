#include "Cure.h"
#include <iostream>


Cure::Cure() : AMateria("cure") 
{
    // std::cout << "Default constructor of Cure" << std::endl;
}
Cure::Cure(Cure const & other) : AMateria(other.getType()) 
{
    // std::cout << "Copy constructor of Cure" << std::endl;
}
Cure::~Cure() 
{
    // std::cout << "Ice Destroyer" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        //do nothing !
    }
    return (*this);
}

std::string const &Cure::getType() const { return type; }

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
Cure *Cure::clone() const
{
    Cure *new_cure = new Cure(*this);
    return (new_cure);
}

std::ostream    &operator<<(std::ostream &out, Cure const &fixed)
{
    out << "Materia : " << fixed.getType();
    return (out);
}