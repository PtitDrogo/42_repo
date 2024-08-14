#pragma once
#include <iostream>
#include "AMateria.h"

//This is the abstract class
//it really only has one type

class Ice : public AMateria
{
public:
    //constructors
    Ice(Ice const &other);
    Ice();
    
    //destructors
    ~Ice();
    //getters
    std::string const &getType() const; // Returns the materia type
    //methods
    Ice *clone() const;
    void use(ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, Ice const &fixed);