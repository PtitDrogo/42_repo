#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <exception>
template <class T> class Array
{
private:
    T*           _array;
    unsigned int _size;
public:
    //Constructors
    Array();
    Array(const Array& other);
    Array(unsigned int n);
    
    //Destructors
    ~Array();

    //Overloads
    Array& operator=(const Array& other);
    T& operator[](unsigned int index);

    //Getters
    const T*     getArray() const;

    //Method
    unsigned int size() const;
    
    class	InvalidIndexException : public std::exception
    {
    public:
        virtual const char	*what() const throw();
    };
};

#include "Array.tpp"

#endif