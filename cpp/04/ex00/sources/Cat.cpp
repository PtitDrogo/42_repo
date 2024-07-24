#include "Animal.h"
#include "Cat.h"
#include <iostream>

Cat::Cat() : type(0), _y(0) {}
Cat::Cat(int a, int b) : 
    type(a), 
    _y(b) 
    {}
Cat::Cat(Cat& other) : 
    type(other.getX()), 
    _y(other.getY()) 
    {}
Cat::~Cat() {}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->type = getX();
        this->_y = getY();
    }
    return (*this);
}


int Cat::getX() const { return type; }
int Cat::getY() const { return _y; }

std::ostream    &operator<<(std::ostream &out, Cat const &fixed)
{
    out << "X is " << fixed.getX() << " Y is " << fixed.getY();
    return (out);
}