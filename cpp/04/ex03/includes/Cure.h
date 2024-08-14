#pragma once
#include <iostream>
#include "AMateria.h"

//This is the abstract class
//it really only has one type

class Cure : public AMateria
{
public:
    //constructors
    Cure(Cure const &other);
    Cure();
    
    //destructors
    ~Cure();
    //getters
    std::string const &getType() const; // Returns the materia type
    //methods
    Cure *clone() const;
    void use(ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, Cure const &fixed);