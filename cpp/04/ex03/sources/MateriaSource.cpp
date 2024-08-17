#include "MateriaSource.h"
#include <iostream>

MateriaSource::~MateriaSource()
{
    // std::cout << "whats up gang MateriaSource Destroyer here" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_materia_source[i])
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (_materia_source[i] == _materia_source[j])
                    _materia_source[j] = NULL; //protect against double delete
            }
            delete _materia_source[i];
        }    
    }   
}

MateriaSource::MateriaSource() : _materia_source(), _last_learned_index(0) 
{
    // for (int i = 0; i < 4; i++)
    // {
    //     if (_materia_source[i] == NULL)
    //         std::cout << "it did init to NULL all good" << std::endl;
    // }
}

MateriaSource::MateriaSource(const MateriaSource &other) : _materia_source(), _last_learned_index(0)
{
    const AMateria * const *other_source = other.getMateriaSource();
    for (int i = 0; i < 4; i++)
    {
        if (other_source[i])
            _materia_source[i] = other_source[i]->clone();
    }
    _last_learned_index = other.getLastLearnedIndex();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        const AMateria * const *other_source = other.getMateriaSource();
        for (int i = 0; i < 4; i++)
        {
            delete _materia_source[i];
            _materia_source[i] = other_source[i]->clone();
        }
        _last_learned_index = other.getLastLearnedIndex();
    }
    return (*this);
}

// methods
void MateriaSource::learnMateria(AMateria *other)
{
    AMateria *new_amateria = other->clone();
    for (int i = 0; i < 4; i++)
    {
        if (_materia_source[i] == NULL) 
        {    
            _materia_source[i] = new_amateria;
            delete other; //Need to fix this if someone wants to learn from the same materia several times
            return ; //J'avais oublier ca UwU
        }
    }
    _materia_source[_last_learned_index] = new_amateria;
    delete other; //Need to fix this if someone wants to learn from the same materia several times
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (type == _materia_source[i]->getType())
        {
            return _materia_source[i]->clone();
        }
    }
    return (0);
}

//getters
const AMateria * const *MateriaSource::getMateriaSource() const { return _materia_source; };
int MateriaSource::getLastLearnedIndex() const { return _last_learned_index; };

std::ostream &operator<<(std::ostream &out, MateriaSource const &fixed)
{
    out << "Materia Source :" << std::endl;
    const AMateria * const *_materias = fixed.getMateriaSource();
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
            out << _materias[i]->getType();
        else
            out << "(NULL)";
        out << std::endl;
    } 
    return (out);
}