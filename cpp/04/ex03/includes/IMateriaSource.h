#pragma once
#include <iostream>
#include "AMateria.h"

//LEAVE THIS UNTOUCHED
class IMateriaSource
{
public:
    virtual ~IMateriaSource() { std::cout << "IMateriaSource destructor\n"; }; //DEBUG REMOVE
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &) = 0;
};

std::ostream &operator<<(std::ostream &o, AMateria const &fixed);