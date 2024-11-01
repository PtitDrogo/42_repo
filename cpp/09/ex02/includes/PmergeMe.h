#ifndef P_MERGE_ME_H
# define P_MERGE_ME_H

#include <vector>
#include <iostream>
#include <algorithm>
class PmergeMe
{
private:
    std::vector<int> _vector;
    
    int              binarySearch(const std::vector<int>& arr, int target);
    std::vector<int> epicSort(std::vector<int>& vector);
    std::vector<int> merge(std::vector<int> &left, std::vector<int> &right);
    std::vector<int> moveLargeElements(std::vector<int>& vector);
    void             binaryInsert(std::vector<int>& vector, std::vector<int>& big_vector);
public:
    //methods
    void fillVector(const int *array, int size);
    void epicSortWrapper();
    
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