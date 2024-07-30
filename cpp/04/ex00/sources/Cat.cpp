#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat(Cat& other) : Animal(other)
{
    std::cout << "Cat copy Constructor" << std::endl;
}
Cat::~Cat() 
{
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

std::ostream    &operator<<(std::ostream &out, Cat const &fixed)
{
    out << fixed.getType() ;
    return (out);
}