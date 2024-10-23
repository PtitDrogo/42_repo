#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:

    //Accessing the Dequeue container and its iterators;
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator const_reverse_iterator;
    
    //methods
    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    reverse_iterator rbegin();
    reverse_iterator rend();

    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;

};

#include "MutantStack.tpp"
#endif