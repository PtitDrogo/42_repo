#pragma once
#include <iostream>
#include "ICharacter.h"

//This is the abstract class
//it really only has one type

class AMateria
{
protected:
    std::string type;
public:
    //constructors
    AMateria(std::string const &type);
    AMateria(AMateria const &other);
    AMateria();
    
    //destructors
    ~AMateria();
    
    //getters
    std::string const &getType() const; // Returns the materia type
    
    //methods
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, AMateria const &fixed);