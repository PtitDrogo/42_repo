#include "AMateria.h"
#include <iostream>

AMateria::AMateria() : _is_equipped(false), type("typeless materia") {}
AMateria::AMateria(std::string const &type) : _is_equipped(false), type(type) 
{
    // std::cout << "type constructor of amateria" << std::endl;
}
AMateria::AMateria(AMateria const & other) : _is_equipped(false), type(other.getType()) 
{
    // std::cout << "copy constructor of amateria" << std::endl;
}
AMateria::~AMateria() 
{
    // std::cout << "whats up gang AMateria Destroyer here" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    // std::cout << "= of amateria here" << std::endl;
    if (this != &other)
    {
        this->type = other.getType();
    }
    return (*this);
}

std::string const &AMateria::getType() const { return type; }
bool AMateria::getIsEquipped() const { return _is_equipped; }
void AMateria::setIsEquipped(bool new_value) { _is_equipped = new_value; }

void    AMateria::use(ICharacter &target)
{
    std::cout << "Currently using default AMateria against " << target.getName() << std::endl;
}


std::ostream    &operator<<(std::ostream &out, AMateria const &fixed)
{
    out << "Materia : " << fixed.getType();
    return (out);
}