#include "Dog.h"
#include "Brain.h"
#include <iostream>

Dog::Dog() : type("Dog"), _Brain(new Brain)
{
    std::cout << "Dog Default Constructor" << std::endl;
}

Dog::Dog(Dog& other) : type(other.getType()), _Brain(new Brain)
{
    *_Brain = *other._Brain;
    std::cout << "Dog copy Constructor" << std::endl;
}
Dog::~Dog() 
{
    delete _Brain;
    std::cout << "Dog Destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignement operator" << std::endl;
    _Brain = new Brain;
    if (this != &other)
    {
        *_Brain = *other._Brain;
        this->type = getType();
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

//Getters
Brain*      Dog::getBrain() const { return _Brain; }
std::string Dog::getType() const { return type; }

std::ostream    &operator<<(std::ostream &out, Dog const &object)
{
    out << object.getType() ;
    return (out);
}