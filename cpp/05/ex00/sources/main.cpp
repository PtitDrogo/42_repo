#include "Bureaucrat.h"
#include <iostream>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define END     "\033[0m"

int main()
{
    Bureaucrat Default;
    Bureaucrat A("John");
    Bureaucrat B(A);
    Bureaucrat C("Scooby Doo", 50);
    Bureaucrat Elite(1);

    std::cout << MAGENTA "Welcome to my main"  END << std::endl << std::endl;

    std::cout << BLUE "Default constructor : " END << WHITE << Default << END << std::endl;
    std::cout << BLUE "Name constructor : " END << WHITE << A << END << std::endl;
    std::cout << BLUE "Copy constructor : " END << WHITE << B << END << std::endl;
    std::cout << BLUE "Name and grade constructor : " END << WHITE << C << END << std::endl;
    std::cout << BLUE "Grade constructor : " END << WHITE << Elite << END << std::endl;
    Default = C;
    std::cout << BLUE "assignement operator, Default = C (scoobydoo) : " END << WHITE << Default << END << YELLOW " (We didnt copy the name since its const !)" END << std::endl;
    
    
    
    std::cout << MAGENTA "Let's increment and decrement some grades" << END << std::endl << std::endl;
    std::cout << BLUE << "Bureaucrat : " << END << WHITE << C << END << BLUE << std::endl << "We will increment his grade" << END << std::endl; 
    try
    {
        C.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Look mom I caught this error : " << e.what()  << END << std::endl;
    }
    std::cout << MAGENTA << "Let's use our getters to find out his grade after the change" << END << std::endl;
    std::cout << BLUE << "Name : " << END << WHITE << C.getName() << END << std::endl;
    std::cout << BLUE << "Grade : " << END << WHITE << C.getGrade() << END << std::endl;

    std::cout << MAGENTA << "You know what this was a mistake actually let's put it back" << END << std::endl;
    try
    {
        C.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Look mom I caught this error : " << e.what()  << END << std::endl;
    }
    std::cout << BLUE << "Name : " << END << WHITE << C.getName() << END << std::endl;
    std::cout << BLUE << "Grade : " << END << WHITE << C.getGrade() << END << std::endl << std::endl;

    
    
    std::cerr << RED << "EXCEPTION TIME" << END << std::endl;
    std::cout << BLUE << "Decrementing the grade of default even tho he's so bad !" << END << std::endl; 
    try
    {
        A.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Look mom I caught this error : " << e.what()  << END << std::endl;
    }
    std::cout << BLUE << "incrementing the grade of elite even tho he's the best !" << END << std::endl; 
    try
    {
        Elite.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Look mom I caught this error : " << e.what()  << END << std::endl;
    }

    std::cout << MAGENTA << "Let's create some faulty bureaucrat" << END << std::endl;
    try
    {
        Bureaucrat test(151);
        std::cout << test.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Look mom I caught this error : " << e.what()  << END << std::endl;
    }
    try
    {
        Bureaucrat test(-12312);
        std::cout << test.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Look mom I caught this error : " << e.what()  << END << std::endl;
    }

    return 0;
}
