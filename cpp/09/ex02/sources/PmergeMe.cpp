#include "PmergeMe.h"


int pairMax(int a, int b) {return a > b ? a : b;}

template <typename Container>
std::ostream &operator<<(std::ostream &out, const PmergeMe<Container> &fixed)
{
    Container vec = fixed.getContainer();
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        out << vec[i] << " ";
    }
    out << std::endl;
    return out;
}
