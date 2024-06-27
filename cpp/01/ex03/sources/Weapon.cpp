#include "main.h"


const std::string& Weapon::getType() const
{
    return (_type);
}

void    Weapon::setType(const std::string type)
{
    _type = type;
}
Weapon::Weapon(std::string type) : _type(type) {}

Weapon::Weapon() {}
Weapon::~Weapon() {}