#ifndef P_MERGE_ME_H
# define P_MERGE_ME_H

#include <vector>
#include <iostream>
class PmergeMe
{
private:
    std::vector<int> _vector;

public:
    //methods
    void fillVector(const int *array, int size);
    int  binarySearch(const std::vector<int>& arr, int target) ;
    void epicSort();
    
    //Constructors
    PmergeMe();
    PmergeMe(PmergeMe& other);
    
    
    //Destructors
    ~PmergeMe();

    //Overloads
    PmergeMe& operator=(const PmergeMe& other);

    //Getters
    const std::vector<int>&getVector() const;
};

std::ostream    &operator<<(std::ostream &o, PmergeMe const &fixed);

#endif