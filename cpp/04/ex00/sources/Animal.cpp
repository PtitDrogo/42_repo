#include "Animal.h"
#include <iostream>

Animal::Animal() : type("no_type") 
{
    std::cout << "Animal Default Constructor" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(Animal& other) : type(other.getType())
{
    std::cout << "Animal copy Constructor" << std::endl;
}
Animal::~Animal() 
{
    std::cout << "Animal Destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal assignement operator" << std::endl;
    if (this != &other)
    {
        this->type = getType();
    }
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const { return type; }

std::ostream    &operator<<(std::ostream &out, Animal const &fixed)
{
    out << fixed.getType() ;
    return (out);
}