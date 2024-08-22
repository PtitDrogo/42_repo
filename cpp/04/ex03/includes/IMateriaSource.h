#pragma once
#include <iostream>
#include "AMateria.h"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}; 
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &) = 0;
};

std::ostream &operator<<(std::ostream &o, AMateria const &fixed);