#pragma once
#include <iostream>
#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_materia_source[4];
    int     _last_learned_index;

public:
    ~MateriaSource();

    // Constructors
    MateriaSource();
    MateriaSource(const MateriaSource &other);

    // overloads
    MateriaSource &operator=(const MateriaSource &other);
    // getters
    const AMateria * const *getMateriaSource() const;
    int getLastLearnedIndex() const;

    // inherited methods
    void learnMateria(AMateria *other);
    AMateria *createMateria(std::string const &type);
};

std::ostream &operator<<(std::ostream &o, AMateria const &fixed);