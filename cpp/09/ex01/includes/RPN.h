#ifndef RPN_H
# define  RPN_H

#include <iostream>
#include <stack>

class RPN
{
private:
    std::stack<int> _stack;

    void    executeCalculation(const char c);
public:

    void    calculateArgsPolishStyle(const char *args);
    //Constructors
    RPN();
    RPN(RPN& other);
    
    //Destructors
    ~RPN();

    //Overloads
    RPN& operator=(const RPN& other);
};

#endif
