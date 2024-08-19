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
    const AMateria * const *other_inventory = other.getInventory();
    
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Deleting inventory of " << getName() << std::endl;
        if (other_inventory[i] != NULL)
            _inventory[i] = other_inventory[i]->clone();
    }
    floor = NULL;
    characters_alive++;
}
Character::~Character()
{
    std::cout << "whats up gang Character Destroyer here" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Deleting inventory of " << getName() << std::endl;
        delete _inventory[i]; // you can call delete on a NULL ptr
    }
    characters_alive--;
    std::cout << "after decrement characters alive is" << characters_alive << std::endl;
    std::cout << "is floor still a thing = " << floor << std::endl;
    if (characters_alive == 0)
        clean_floor();
    std::cout << "is floor still a thing = " << floor << std::endl;
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
                std::cout << "equiping weapon" << *m << std::endl;
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
    // new_node->next = NULL;
    if (floor == NULL)
    {
        std::cout << "Adding Weapon to the GC !" << std::endl;
        floor = new_node;
        floor->next = NULL;
    }
    else
    {
        new_node->next = floor; //I am doing prepending;
        floor = new_node;
    }
    std::cout << "At the end of adding, floor = " << floor << std::endl;
    if (floor)
    {
        std::cout << "At the end of adding, next = " << floor->next << std::endl;
    }
    else
    {
        std::cout << "At the end of adding, next = NULL" << std::endl;
    }
}

void Character::pop_from_gc(AMateria *m)
{
    t_gc *tmp;
    t_gc *current;

    current = floor;
    if (m == NULL)
        return ;
    if (current && current->next == NULL)
    {
        delete floor;
        floor = NULL;
        return ;
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

    std::cout << getName() << " is about to clean Floor ! and floor is == " << floor << std::endl;
    while (floor != NULL)
    {
        std::cout << getName() << " is Cleaning Floor and floor next is " << floor->next << std::endl;
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
    std::cout << getName() << " and before adding to gc floor == " << floor << std::endl;
    if (idx > 3 || idx < 0)
        return;
    if (_inventory[idx])
    {
        add_to_gc(_inventory[idx]); //Add to floor and takes away from inventory;
        _inventory[idx]->setIsEquipped(false);
    }
    _inventory[idx] = NULL;
    std::cout << getName() << " and After adding to gc floor == " << floor << std::endl;
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
