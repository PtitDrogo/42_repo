#pragma once
#include <iostream>
#include "AMateria.h"

class Cure : public AMateria
{
public:
    //constructors
    Cure(Cure const &other);
    Cure();
    
    //destructors
    ~Cure();

    //overloads
    Cure& operator=(const Cure& other);
    
    //getters
    std::string const &getType() const; // Returns the materia type
    
    //methods
    Cure *clone() const;
    void use(ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, Cure const &fixed);