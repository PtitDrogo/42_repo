#pragma once
#include <iostream>
#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_materia_source[4];

public:
    ~MateriaSource();

    // Constructors
    MateriaSource();
    MateriaSource(const MateriaSource &other);

    // overloads
    MateriaSource &operator=(const MateriaSource &other);
    // getters
    const AMateria *getMateriaSource() const;

    // inherited methods
    void learnMateria(AMateria *other);
    AMateria *createMateria(std::string const &type);
};

//useless / impossible to use ?
std::ostream &operator<<(std::ostream &o, AMateria const &fixed);