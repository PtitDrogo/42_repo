#include "Span.h"


Span::Span() {}
Span::~Span() {} //A vector clears itself when going out of scope


Span::Span(unsigned int n)
{
    _span.reserve(n);
}

Span &Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _span = other._span;
    }
    return (*this);
}

Span::Span(const Span&other) : _span(other._span) {}

void Span::addNumber(const int n)
{
    if (_span.size() >= _span.capacity())
        throw SpanFullError();
    else
        _span.push_back(n);
}

void Span::addManyNumbers(const std::vector<int>& numbers)
{
    if (_span.size() + numbers.size() > _span.capacity())
        throw NewVectorTooBigError();
    std::cout << "I am the add many numbers function, you see me once, but I am adding " << numbers.size() << "numbers !" << std::endl;
    _span.insert(_span.end(), numbers.begin(), numbers.end());
}

int Span::shortestSpan()
{
    std::sort(_span.begin(), _span.end());
    if (_span.size() <= 1)
        throw TooSmallSizeError();
    int shortest_span = _span[1] - _span[0];; 
    for (unsigned int i = 1; i < _span.size(); i++)
    {
        if (_span[i] - _span[i - 1] > shortest_span)
            shortest_span = _span[i] - _span[i - 1];
    }
    return (shortest_span);
}

int Span::longestSpan()
{
    if (_span.size() <= 1)
        throw TooSmallSizeError();
    std::vector<int>::iterator small = std::min_element(_span.begin(), _span.end());
    std::vector<int>::iterator big = std::max_element(_span.begin(), _span.end());
    return (*big - *small);
}


 void Span::printSpan()
 {
    int end = _span.size();
    for (int i = 0; i < end; i++)
    {
        std::cout << _span[i];
        if (i + 1 != end)
            std::cout << ", ";
    }
    std::cout << std::endl;
 }
