#include "Animal.h"
#include <iostream>

Animal::Animal() : type("no_type") {}
Animal::Animal(std::string type) : type(type) {}
Animal::Animal(Animal& other) : type(other.getType()){}
Animal::~Animal() {}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->type = getType();
    }
    return (*this);
}


std::string Animal::getType() const { return type; }

std::ostream    &operator<<(std::ostream &out, Animal const &fixed)
{
    out << fixed.getType() ;
    return (out);
}