#pragma once
#include <iostream>
#include "ICharacter.h"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria    *_inventory[4];
    int         last_equip_index;
public:
    
    //Constructors
    Character(std::string const &name);
    Character(Character const &other);
    Character();

    //overloads
    Character& operator=(const Character& other);

    //Destructor
    ~Character();

    //getters
    std::string const &getName() const;
    const AMateria* getInventory() const;
    //inherited methods
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

};

std::ostream &operator<<(std::ostream &o, Character const &fixed);