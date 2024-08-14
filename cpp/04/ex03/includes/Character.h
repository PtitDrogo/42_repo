#pragma once
#include <iostream>
#include "ICharacter.h"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *_inventory[4];
public:
    
    //Constructors
    Character(std::string const &name);
    Character(Character const &other);
    Character();

    //Destructor
    ~Character();

};