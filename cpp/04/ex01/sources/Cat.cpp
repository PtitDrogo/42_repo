#include "Cat.h"
#include "Brain.h"
#include <iostream>

Cat::Cat() : type("Cat") 
{
    _Brain = new Brain;
    std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat(Cat& other) : type(other.getType())
{
    std::cout << "Cat copy Constructor" << std::endl;
}
Cat::~Cat() 
{
    delete _Brain;
    std::cout << "Cat Destructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignement operator" << std::endl;
    if (this != &other)
    {
        this->type = getType();
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

std::string Cat::getType() const { return type; }

std::ostream    &operator<<(std::ostream &out, Cat const &object)
{
    out << object.getType() ;
    return (out);
}