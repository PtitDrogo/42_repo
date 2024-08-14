#include "Character.h"
#include <iostream>

Character::Character() : ICharacter(), _name("no_name") {}
Character::Character(const std::string &name) : ICharacter(), _name(name) {}
Character::Character(const Character& other) : ICharacter(), _name(other.getName()) {}
Character::~Character() 
{
    //Maybe delete inventory here;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_x = getX();
        this->_y = getY();
    }
    return (*this);
}


std::string const &Character::getName() const { return _name; }

std::ostream    &operator<<(std::ostream &out, Character const &fixed)
{
    out << "Character is " << fixed.getName();
    return (out);
}