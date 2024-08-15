#include "AMateria.h"
#include <iostream>

AMateria::AMateria() : type("typeless materia") {}
AMateria::AMateria(std::string const &type) : type(type) {}
AMateria::AMateria(AMateria const & other) : type(other.getType()) {}
AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->type = other.getType();
    }
    return (*this);
}

std::string const &AMateria::getType() const { return type; }

//Need to implement use

void    AMateria::use(ICharacter &target)
{
    std::cout << "Currently using against the target !" << std::endl;
}


std::ostream    &operator<<(std::ostream &out, AMateria const &fixed)
{
    out << "Materia : " << fixed.getType();
    return (out);
}