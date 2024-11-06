#ifndef P_MERGE_ME_H
# define P_MERGE_ME_H

#include <vector>
#include <iostream>
#include <algorithm>
template<typename Container>
class PmergeMe
{
private:
    Container _container;
    
    // typedef typename Container::value_type  value_type;
    // typedef typename Container::size_type   size_type;
    // typedef typename Container::iterator   iterator;
    // typedef typename Container::const_iterator   const_iterator;
    
    int              binarySearch(const Container& arr, int target);
    Container        epicSort(Container& vector);
    Container        merge(Container& left, Container &right);
    Container        moveLargeElements(Container& vector);
    void             binaryInsert(Container& vector, Container& big_vector);
public:
    //methods
    void fillContainer(const int *array, int size);
    void epicSortWrapper();
    size_t size() const;
    
    //Constructors
    PmergeMe();
    PmergeMe(PmergeMe& other);
    
    
    //Destructors
    ~PmergeMe();

    //Overloads
    PmergeMe& operator=(const PmergeMe& other);

    //Getters
    const Container&getContainer() const;
};

int pairMax(int a, int b);

template <typename Container>
std::ostream &operator<<(std::ostream &out, const PmergeMe<Container> &fixed);

#include "PmergeMe.tpp"
#endif