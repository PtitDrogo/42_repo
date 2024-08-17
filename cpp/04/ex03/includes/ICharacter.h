#pragma once
#include <iostream>
#include "AMateria.h"

class AMateria;
//LEAVE THIS UNTOUCHED
class ICharacter
{
public:
    virtual ~ICharacter() { std::cout << "ICharacter destructor\n"; }; //DEBUG REMOVE;
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
};