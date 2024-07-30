#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal() : type("no_type_wrong") 
{
    std::cout << "WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& other) : type(other.getType())
{
    std::cout << "WrongAnimal copy Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal assignement operator" << std::endl;
    if (this != &other)
    {
        this->type = getType();
    }
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }

std::ostream    &operator<<(std::ostream &out, WrongAnimal const &fixed)
{
    out << fixed.getType() ;
    return (out);
}