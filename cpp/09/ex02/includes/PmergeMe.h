#ifndef P_MERGE_ME_H
# define P_MERGE_ME_H

#include <vector>
#include <iostream>
class PmergeMe
{
private:
    std::vector<int> _vector;

public:
    //Constructors
    PmergeMe();
    PmergeMe(PmergeMe& other);
    
    //Destructors
    ~PmergeMe();

    //Overloads
    PmergeMe& operator=(const PmergeMe& other);

    //Getters
};

std::ostream    &operator<<(std::ostream &o, PmergeMe const &fixed);

#endif