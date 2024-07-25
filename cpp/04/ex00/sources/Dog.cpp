#include "Dog.h"
#include <iostream>

Dog::Dog() : type("Dog") 
{
    std::cout << "Dog Default Constructor" << std::endl;
}

Dog::Dog(Dog& other) : type(other.getType())
{
    std::cout << "Dog copy Constructor" << std::endl;
}
Dog::~Dog() 
{
    std::cout << "Dog Destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignement operator" << std::endl;
    if (this != &other)
    {
        this->type = getType();
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

std::string Dog::getType() const { return type; }

std::ostream    &operator<<(std::ostream &out, Dog const &fixed)
{
    out << fixed.getType() ;
    return (out);
}