#include "PmergeMe.h"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe& other) : _vector(other._vector)
{}
PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
    }
    return (*this);
}


std::ostream    &operator<<(std::ostream &out, PmergeMe const &fixed)
{
    //Nothing yet;
    (void) fixed;
    return (out);
}