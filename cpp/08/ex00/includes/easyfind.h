#ifndef EASYFIND_H
# define EASYFIND_H
#include <iostream>
#include <exception>
# include <algorithm>

template <typename T>
typename T::iterator easyFind(T& array, int to_find);


#include "easyfind.tpp"

#endif