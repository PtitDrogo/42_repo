#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.h"
#include <cstdlib>  
#include <ctime> 

template <typename T> 
Array<T>::Array() : _array(), _size(0) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other.size()]), _size(other.size())
{
    for (unsigned int i = 0; i < _size; i++)
    {
        _array[i] = other[i]; //doute
    }
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
    for (unsigned int i = 0; i < _size; i++)
    {
        _array[i] = 0; //doute
    }
}

template <typename T>
Array<T>::~Array()
{
    for (unsigned int i = 0; i < _size; i++)
    {
        delete _array[i];
    }
    //do i need to set the inside of the array to NULL ?
}


//getters
template <typename T> unsigned int Array<T>::size() const {return (_size);}
template <typename T> const T* Array<T>::getArray() const {return (_array);}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index > _size)
        throw InvalidIndexException();
    return (_array[index]);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    for (unsigned int i = 0; i < _size; i++)
    {
        delete _array[i];
    }
    _size = other.size();
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
    {
        _array[i] = other[i];
    }
}

template< typename T >
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error: Invalid index");
}



#endif