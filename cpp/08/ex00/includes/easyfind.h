#ifndef EASYFIND_H
# define EASYFIND_H
#include <iostream>
#include <exception>
# include <algorithm>

template <typename T>
int easyFind(T& array, int to_find);

class IndexNotFound : public std::exception
{
public:    
    virtual const char *what() const throw();
};


#include "easyfind.tpp"

#endif