#include "MutantStack.h"


#define MAGENTA "\033[1;35m"
#define END     "\033[0m"

int main()
{       
    std::cout << MAGENTA << "SUBJECT TESTS:" << END << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    std::cout << "The top of my Stack is : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "After poping, size of my stack is : ";
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Before copying, here is the state of my stack" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    //I can create a stack (Parent class) from a mstack (Child Class);
    std::stack<int> s(mstack);
    
    //TESTING CANONICAL FORM
    std::cout << MAGENTA << "TESTING CANONICAL FORM AND OTHER TYPES OF ITERATORS" << END << std::endl;
    MutantStack<int> new_stack(mstack);
    std::cout << "The top of my Stack is : " << new_stack.top() << std::endl;
    it = new_stack.begin();
    ite = new_stack.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << MAGENTA << "TESTING CONST REVERSE ITERATOR AND ASSIGNEMENT" << END << std::endl;
    MutantStack<int> new_stack_2 = mstack;
    std::cout << "The top of my Stack is : " << new_stack_2.top() << std::endl;
    MutantStack<int>::const_reverse_iterator itreverse = new_stack_2.rbegin();
    MutantStack<int>::const_reverse_iterator itereverse = new_stack_2.rend();
    while (itreverse != itereverse)
    {
        std::cout << *itreverse << std::endl;
        ++itreverse;
    }
    return (0);
}
