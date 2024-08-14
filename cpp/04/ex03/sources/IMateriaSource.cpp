#include "ICharacter.h"
#include <iostream>

ICharacter::ICharacter() : _x(0), _y(0) {}
ICharacter::ICharacter(int a, int b) : 
    _x(a), 
    _y(b) 
    {}
ICharacter::ICharacter(ICharacter& other) : 
    _x(other.getX()), 
    _y(other.getY()) 
    {}
ICharacter::~ICharacter() {}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
    if (this != &other)
    {
        this->_x = getX();
        this->_y = getY();
    }
    return (*this);
}

int ICharacter::getX() const { return _x; }
int ICharacter::getY() const { return _y; }

std::ostream    &operator<<(std::ostream &out, ICharacter const &fixed)
{
    out << "X is " << fixed.getX() << " Y is " << fixed.getY();
    return (out);
}