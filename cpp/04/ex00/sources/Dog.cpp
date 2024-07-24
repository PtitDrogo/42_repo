#include "Animal.h"
#include "Dog.h"
#include <iostream>

Dog::Dog() : type(0), _y(0) {}
Dog::Dog(int a, int b) : 
    type(a), 
    _y(b) 
    {}
Dog::Dog(Dog& other) : 
    type(other.getX()), 
    _y(other.getY()) 
    {}
Dog::~Dog() {}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->type = getX();
        this->_y = getY();
    }
    return (*this);
}


int Dog::getX() const { return type; }
int Dog::getY() const { return _y; }

std::ostream    &operator<<(std::ostream &out, Dog const &fixed)
{
    out << "X is " << fixed.getX() << " Y is " << fixed.getY();
    return (out);
}