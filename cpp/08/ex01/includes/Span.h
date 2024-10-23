#ifndef Span_H
# define Span_H
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>


class Span
{
    private:
        std::vector<int> _span;
    Span();

    public:
    Span(unsigned int n);
    Span(const Span& other);
    ~Span();

    Span& operator=(const Span& other);

    //method
    void addNumber(const int n);
    void addManyNumbers(const std::vector<int>& numbers);
    int  shortestSpan();
    int  longestSpan();
    void printSpan();
};

class SpanFullError : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("Cannot add number, span is full");
    }
};

class TooSmallSizeError : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("Cannot call method, Vector is too small");
    }
};

class NewVectorTooBigError : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("Cannot insert vector of numbers, it exceeds vector capacity");
    }
};


/*
This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.*/

// #include "Span.tpp"

#endif