#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <iostream>
#include "easyfind.h"

template <typename T>
int easyFind(T& container, int to_find)
{
    typename T::iterator result = std::find(container.begin(), container.end(), to_find);
    if (result == container.end())
        throw IndexNotFound();
    std::cout << "element " << to_find << " has been found at index " << result << std::endl;
    return result;
}

const char *IndexNotFound::what(void) const throw()
{
    return ("Couldn't find the element");
};


#endif