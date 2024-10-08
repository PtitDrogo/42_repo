#include "Cat.h"
#include "Brain.h"
#include <iostream>

Cat::Cat() : Animal("Cat"), _Brain(new Brain)
{
    std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _Brain(new Brain)
{
    *_Brain = *other._Brain;
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
        delete _Brain;
        _Brain = new Brain;
        *_Brain = *other._Brain;
        this->type = other.getType();
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

//Getters
Brain*      Cat::getBrain() const { return _Brain; }

std::ostream    &operator<<(std::ostream &out, Cat const &object)
{
    out << object.getType() ;
    return (out);
}