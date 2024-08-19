#pragma once
#include <iostream>
#include "IMateriaSource.h"

# ifndef GC
#  define GC
typedef struct s_gc
{
    AMateria *to_free;
    s_gc *next;
} t_gc;
# endif

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_materia_source[4];
    static t_gc     *floor;
    static int      materias_source_alive;
    
    // private methods
    void add_to_gc(AMateria *m);
    void pop_from_gc(AMateria *m);
    void clean_floor();

public:
    ~MateriaSource();

    // Constructors
    MateriaSource();
    MateriaSource(const MateriaSource &other);

    // overloads
    MateriaSource &operator=(const MateriaSource &other);
    // getters
    const AMateria *const *getMateriaSource() const;

    // inherited methods
    void learnMateria(AMateria *other);
    AMateria *createMateria(std::string const &type);
};

std::ostream &operator<<(std::ostream &o, AMateria const &fixed);