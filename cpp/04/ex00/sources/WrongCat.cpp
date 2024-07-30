#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") 
{
    std::cout << "WrongCat Default Constructor" << std::endl;
}

WrongCat::WrongCat(WrongCat& other) :  WrongAnimal(other.getType())
{
    std::cout << "WrongCat copy Constructor" << std::endl;
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat assignement operator" << std::endl;
    if (this != &other)
    {
        this->type = getType();
    }
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Salut c'est greg" << std::endl;
}

std::string WrongCat::getType() const { return type; }

std::ostream    &operator<<(std::ostream &out, WrongCat const &fixed)
{
    out << fixed.getType() ;
    return (out);
}