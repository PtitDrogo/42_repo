#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <iostream>
#include "easyfind.h"

template <typename T>
typename T::iterator easyFind(T& container, int to_find)
{
    typename T::iterator result = std::find(container.begin(), container.end(), to_find);
    return (result);
}

#endif