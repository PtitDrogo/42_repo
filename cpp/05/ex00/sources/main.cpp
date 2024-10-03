#include "Bureaucrat.h"
#include <iostream>

int main()
{
    Bureaucrat A("John");
    Bureaucrat B(A);
    
    try
    {
        A.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Look mom I caught an error" << std::endl;
    }
    
    std::cout << A << std::endl;
    std::cout << B << std::endl;

    return 0;
}
