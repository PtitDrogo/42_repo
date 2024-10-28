#ifndef P_MERGE_ME_LIST_H
# define P_MERGE_ME_LIST_H

#include <iostream>
#include <list>

class PmergeMeList
{
private:
    std::list<int> _list;

public:
    //Constructors
    PmergeMeList();
    PmergeMeList(PmergeMeList& other);
    
    //Destructors
    ~PmergeMeList();

    //Overloads
    PmergeMeList& operator=(const PmergeMeList& other);

    //Getters
};

std::ostream    &operator<<(std::ostream &o, PmergeMeList const &fixed);
#endif