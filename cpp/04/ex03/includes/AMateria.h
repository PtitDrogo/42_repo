#pragma once
#include <iostream>
#include "ICharacter.h"

// This is the abstract class
// it really only has one type

class ICharacter;


class AMateria
{
private:
    bool _is_equipped;

protected:
    std::string type;

public:
    // constructors
    AMateria(std::string const &type);
    AMateria(AMateria const &other);
    AMateria();

    // destructors
    virtual ~AMateria();

    // overloads
    AMateria &operator=(const AMateria &other);

    // getters
    std::string const &getType() const;
    bool getIsEquipped() const;

    // setters
    void setIsEquipped(bool new_value);

    // methods
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, AMateria const &fixed);