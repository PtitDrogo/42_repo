#include "MateriaSource.h"
#include <iostream>

t_gc *MateriaSource::purgatory = NULL;

MateriaSource::~MateriaSource()
{
    // std::cout << "MAteriaSource Destructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_materia_source[i])
        {
            delete_from_purgatory(_materia_source[i]);
        }
    }
}

MateriaSource::MateriaSource() : _materia_source()
{
    // std::cout << "Default MAteriaSource Constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) : _materia_source()
{
    // std::cout << "MAteriaSource Copy Constructor" << std::endl;
    const AMateria *const *other_source = other.getMateriaSource();
    for (int i = 0; i < 4; i++)
    {
        if (other_source[i])
        {
            _materia_source[i] = other_source[i]->clone();
            add_to_gc(_materia_source[i]);
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        const AMateria *const *other_source = other.getMateriaSource();
        for (int i = 0; i < 4; i++)
        {
            delete_from_purgatory(_materia_source[i]);
            _materia_source[i] = other_source[i]->clone();
            add_to_gc(_materia_source[i]);
        }
    }
    return (*this);
}

// methods
void MateriaSource::learnMateria(AMateria *other)
{
    if (other == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (_materia_source[i] == NULL)
        {
            _materia_source[i] = other;
            add_to_gc(_materia_source[i]);
            return;
        }
    }
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia_source[i] && type == _materia_source[i]->getType())
        {
            return _materia_source[i]->clone();
        }
    }
    return (0);
}

// GC METHODS
void MateriaSource::delete_from_purgatory(AMateria *m)
{
    if (m == NULL)
        return;

    t_gc *current = purgatory;
    t_gc *tmp_node;
    AMateria *tmp_AMateria = NULL;

    while (current)
    {
        if (current->to_free == m)
        {
            if (is_singleton(current) == true)
            {
                tmp_AMateria = current->to_free;
            }
            tmp_node = current;
            current = current->next;
            pop_from_gc(tmp_node->to_free);
            delete tmp_AMateria;
        }
        else
            current = current->next;
    }
}
bool MateriaSource::is_singleton(t_gc *node)
{
    t_gc *search_node;

    search_node = node->next;
    while (search_node)
    {
        if (search_node->to_free == node->to_free)
        {
            return false;
        }
        search_node = search_node->next;
    }
    return true;
}

void MateriaSource::add_to_gc(AMateria *m)
{
    if (m == NULL)
        return;

    t_gc *new_node = new t_gc;
    new_node->to_free = m;

    if (purgatory == NULL)
    {
        purgatory = new_node;
        purgatory->next = NULL;
    }
    else
    {
        new_node->next = purgatory; // I am doing prepending;
        purgatory = new_node;
    }
}

// This doesnt free the memory to free, just the node;
void MateriaSource::pop_from_gc(AMateria *m)
{
    t_gc *tmp;
    t_gc *current = purgatory;

    if (m == NULL)
        return;
    if (current && current->to_free == m)
    {
        tmp = current;
        purgatory = purgatory->next; // moving the actual pointer;
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

// getters
const AMateria *const *MateriaSource::getMateriaSource() const { return _materia_source; };

std::ostream &operator<<(std::ostream &out, MateriaSource const &fixed)
{
    out << "Materia Source :" << std::endl;
    const AMateria *const *_materias = fixed.getMateriaSource();
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