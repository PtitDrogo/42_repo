#include "PmergeMeList.h"

PmergeMeList::PmergeMeList() {}
PmergeMeList::PmergeMeList(PmergeMeList& other) : _list(other._list)
{}
PmergeMeList::~PmergeMeList() {}

PmergeMeList& PmergeMeList::operator=(const PmergeMeList& other)
{
    if (this != &other)
    {
        _list = other._list;
    }
    return (*this);
}


std::ostream    &operator<<(std::ostream &out, PmergeMeList const &fixed)
{
    //Nothing yet;
    (void) fixed;
    return (out);
}