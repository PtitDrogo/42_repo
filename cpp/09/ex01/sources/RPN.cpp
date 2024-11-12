#include "RPN.h"
#include <iostream>
#include <cstring>
#include <limits.h>

RPN::RPN() {}
RPN::RPN(RPN &other) : _stack(other._stack)
{
}
RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return (*this);
}

void RPN::calculateArgsPolishStyle(const char *args)
{
    static const char operators[] = {'+', '-', '*', '/', '\0'};
    char c;
    if (args == NULL || *args == '\0')
        throw std::runtime_error("NULL/Empty string");
    for (int i = 0; args[i]; i++)
    {
        c = args[i];
        if (c == ' ')
            continue;
        else if (strchr(operators, c) != NULL)
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Operation without two numbers in stack");
            executeCalculation(c);
        }
        else if (isdigit(c))
        {
            if (isdigit(args[i + 1]))
                throw std::runtime_error("Only single digits accepted");
            _stack.push(static_cast<int>(c - '0'));
        }
        else
            throw std::runtime_error("Invalid char found");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Unvalid digit to operator ratio");
    std::cout << _stack.top() << std::endl;
}

void RPN::executeCalculation(const char c)
{
    long long first;
    long long second;
    long long result;

    first = _stack.top();
    _stack.pop();
    second = _stack.top();
    _stack.pop();

    switch (c)
    {
    case '+':
        result = second + first;
        break;
    case '-':
        result = second - first;
        break;
    case '*':
        result = second * first;
        break;
    case '/':
        if (first == 0)
            throw std::runtime_error("Tried to divide by 0");
        else
            result = second / first;
        break;
    default:
        throw std::runtime_error("Unknown error");
        break;
    }
    if (result > INT_MAX || result < INT_MIN)
        throw std::runtime_error("Overflow/Underflow");
    _stack.push(static_cast<int>(result));
}
