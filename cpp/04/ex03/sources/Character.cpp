#include "Character.h"
#include <iostream>

Character::Character() : ICharacter(), _name("no_name"), _inventory{NULL, NULL, NULL, NULL}, last_equip_index(0) {}
Character::Character(const std::string &name) : ICharacter(), _name(name), _inventory{NULL, NULL, NULL, NULL}, last_equip_index(0) {}
Character::Character(const Character &other) : ICharacter(), _name(other.getName())
{
    //_inventory{NULL, NULL, NULL, NULL}, last_equip_index(0)
    // Copy this from the other character;
}
Character::~Character()
{
    for (int i = 0; i < 3; i++)
    {
        delete _inventory[i]; // you can call delete on a NULL ptr
    }
    // Check later for how to handle unequipped AMateria
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 3; i++)
        {
            delete _inventory[i];
            // Deep copy here, harder than i thought;
        }
    }
    return (*this);
}

// methods
void Character::equip(AMateria *m)
{
    // I want to add the materia in parameters to the inventory;
    int i = 0;

    while (i < 3)
    {
        if (_inventory[i] == NULL)
        {
            //Add a condition so we dont add the same materia twice to the inventory
            _inventory[i] = m;
            return;
        }
        i++;
    }
    _inventory[last_equip_index] = m;
    last_equip_index++;
    if (last_equip_index > 3)
        last_equip_index = 0;
}
void Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
        return;
    _inventory[idx] = NULL; // this doesnt free the materia, check again later;
    // Take away from the inventory
}
void Character::use(int idx, ICharacter &target)
{
    if (idx > 3 || idx < 0)
        return;
    if (_inventory[idx])
        (*_inventory[idx]).use(target);
}

// getters
std::string const &Character::getName() const { return _name; }
const AMateria *Character::getInventory() const { return *_inventory; };
// returns a pointer to the first element of the inventory

std::ostream &operator<<(std::ostream &out, Character const &fixed)
{
    out << "Character is " << fixed.getName();
    return (out);
}