#include "Character.h"
#include <iostream>

int      Character::characters_alive = 0;
t_gc     *Character::floor = NULL;

Character::Character() : ICharacter(), _name("no_name"), _inventory()
{
    characters_alive++;
}
Character::Character(const std::string &name) : ICharacter(), _name(name), _inventory() 
{
    characters_alive++;
}
Character::Character(const Character &other) : ICharacter(),  _name(other.getName()), _inventory()
{
    // std::cout << "Copy Constructor " << getName() << std::endl;
    const AMateria * const *other_inventory = other.getInventory();
    
    for (int i = 0; i < 4; i++)
    {
        if (other_inventory[i] != NULL)
            _inventory[i] = other_inventory[i]->clone();
    }
    characters_alive++;
}
Character::~Character()
{
    // std::cout << "Character Destroyer" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete _inventory[i]; // you can call delete on a NULL ptr
    }
    characters_alive--;
    if (characters_alive == 0)
        clean_floor();
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
    {    
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            if (is_already_equipped(m) == false)
            {    
                _inventory[i] = m;
                m->setIsEquipped(true);
                pop_from_gc(m); 
            }
            return;
        }
    }
}
//Private methods
bool Character::is_already_equipped(AMateria *m)
{
    return (m->getIsEquipped());
}
void Character::add_to_gc(AMateria *m)
{
    if (m == NULL)
        return ;

    t_gc *new_node = new t_gc;
    new_node->to_free = m;
    if (floor == NULL)
    {
        floor = new_node;
        floor->next = NULL;
    }
    else
    {
        new_node->next = floor; //I am doing prepending;
        floor = new_node;
    }
}

void Character::pop_from_gc(AMateria *m)
{
    t_gc *tmp;
    t_gc *current = floor;

    if (m == NULL)
        return ;
    if (current && current->to_free == m)
    {
        tmp = current;
        floor = floor->next; // moving the actual pointer;
        delete tmp;
        return;
    }
    while (current)
    {
        if (current->next && current->next->to_free == m)
        {
            tmp = current->next;
            current->next = current->next->next;
            delete tmp;
            return;
        }   
        current = current->next;
    }
}

void Character::clean_floor()
{
    t_gc *tmp;

    while (floor != NULL)
    {
        tmp = floor;
        floor = floor->next;
        delete tmp->to_free;
        delete tmp;
    }
    floor = NULL;
}

//Public Methods
void Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
        return;
    if (_inventory[idx])
    {
        //Add to floor and takes away from inventory;
        add_to_gc(_inventory[idx]); 
        _inventory[idx]->setIsEquipped(false);
    }
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
    out << "Character is " << fixed.getName() << std::endl;
    out << "His inventory is : " << std::endl;
    const AMateria *const *inventory = fixed.getInventory();
    for (int i = 0; i < 4; i++)
    {
        out << "Slot " << i << " : ";
        if (inventory[i])
        {
            out << *inventory[i];
        }
        else
            out << "NULL";
        if (i != 3)
            out << std::endl;
    }
    return (out);
}
