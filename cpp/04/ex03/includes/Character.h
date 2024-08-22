#pragma once
#include <iostream>
#include "ICharacter.h"

# ifndef GC
#  define GC
    typedef struct s_gc
    {
        AMateria *to_free;
        s_gc *next;
    } t_gc;
# endif
class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *_inventory[4];
    static t_gc *floor;
    static int characters_alive;

    // private methods
    bool is_already_equipped(AMateria *m);
    void add_to_gc(AMateria *m);
    void pop_from_gc(AMateria *m);
    void clean_floor();

public:
    // Constructors
    Character(std::string const &name);
    Character(Character const &other);
    Character();

    // overloads
    Character &operator=(const Character &other);

    // Destructor
    ~Character();

    // getters
    std::string const &getName() const;
    const AMateria *const *getInventory() const;

    // inherited methods
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, Character const &fixed);