#include "MateriaSource.h"
#include <iostream>

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete _materia_source[i];
        _materia_source[i] = NULL; //Setting NULL so we dont double delete
    }
}
MateriaSource::MateriaSource() : _materia_source{NULL, NULL, NULL, NULL} {}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    const AMateria *other_source = other.getMateriaSource();
    for (int i = 0; i < 4; i++)
    {
        delete _materia_source[i];
        _materia_source[i] = other_source[i].clone();
        //I think this will work but maybe no ! We will see;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        // Deep copy of the materia here;
    }
    return (*this);
}

// methods
void MateriaSource::learnMateria(AMateria *other)
{
    AMateria *new_amateria = other->clone();
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 3; i++)
    {
        if (type == _materia_source[i]->getType())
        {
            return _materia_source[i]->clone();
        }
    }
    return (0);
}

const AMateria *MateriaSource::getMateriaSource() const { return *_materia_source; };

std::ostream &operator<<(std::ostream &out, MateriaSource const &fixed)
{
    out << "Materia Source here";
    return (out);
}