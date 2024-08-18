#include "Character.h"
#include <iostream>

Character::Character() : ICharacter(), _name("no_name"), _inventory() {}
Character::Character(const std::string &name) : ICharacter(), _name(name), _inventory() {}
Character::Character(const Character &other) : ICharacter(),  _name(other.getName()), _inventory()
{
    const AMateria * const *other_inventory = other.getInventory();
    
    for (int i = 0; i < 4; i++)
    {
        if (other_inventory[i] != NULL)
            _inventory[i] = other_inventory[i]->clone();
    }
}
Character::~Character()
{
    std::cout << "whats up gang Character Destroyer here" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete _inventory[i]; // you can call delete on a NULL ptr
    }
}

Character &Character::operator=(const Character &other)
{
    const AMateria * const *other_inventory = other.getInventory();
    
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            if (other_inventory[i] != NULL)
                _inventory[i] = other_inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    _name = other.getName();
    return (*this);
}

// methods
void Character::equip(AMateria *m)
{
    if (m == NULL)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            if (is_already_equipped(m) == false)
            {    
                _inventory[i] = m;
            }
            return;
        }
    }
}

bool Character::is_already_equipped(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == m)
            return true;
    }
    return false;
}
void Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
        return;
    _inventory[idx] = NULL;
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
const AMateria * const *Character::getInventory() const { return _inventory; };


std::ostream &operator<<(std::ostream &out, Character const &fixed)
{
    out << "Character is " << fixed.getName();
    return (out);
}
