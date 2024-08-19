#include "MateriaSource.h"
#include <iostream>

static t_gc     *floor = NULL;
static int      materias_source_alive = 0;

MateriaSource::~MateriaSource()
{
    // std::cout << "whats up gang MateriaSource Destroyer here" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_materia_source[i])
        {
            // for (int j = i + 1; j < 4; j++)
            // {
            //     if (_materia_source[i] == _materia_source[j])
            //         _materia_source[j] = NULL; //protect against double delete
            // }
            delete _materia_source[i];
        }    
    }   
}

MateriaSource::MateriaSource() : _materia_source()
{
    materias_source_alive++;
    // for (int i = 0; i < 4; i++)
    // {
    //     if (_materia_source[i] == NULL)
    //         std::cout << "it did init to NULL all good" << std::endl;
    // }
}

MateriaSource::MateriaSource(const MateriaSource &other) : _materia_source()
{
    const AMateria * const *other_source = other.getMateriaSource();
    for (int i = 0; i < 4; i++)
    {
        if (other_source[i])
            _materia_source[i] = other_source[i]->clone();
    }
    materias_source_alive++;
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
    }
    return (*this);
}

// methods
//THIS NEEDS TO COPY THE POINTER IN MEMORY FUCK MY LIFE
//The only thing we have to handle then is to potentially free the other ptr;
//We add the ptr to a linked list. when do we delete it ?
void MateriaSource::learnMateria(AMateria *other)
{
    if (other == NULL)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (_materia_source[i] == NULL)
        {
            _materia_source[i] = other->clone();
            return ; 
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
//GC METHODS
void MateriaSource::add_to_gc(AMateria *m)
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

void MateriaSource::pop_from_gc(AMateria *m)
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

void MateriaSource::clean_floor()
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



//getters
const AMateria * const *MateriaSource::getMateriaSource() const { return _materia_source; };

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