#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <cstdlib>  
#include <ctime>    
#include <iostream>

static Base *generate(void);
static void identify(Base* p);
static void identify(Base& p);

int main(void)
{
    Base *randomsubclass = generate();
    identify(randomsubclass);
    identify(*randomsubclass);
    delete randomsubclass;
    return (0);
}


static Base *generate(void)
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = (rand() % 3) + 1;
    if (randomNumber == 1)
        return new A;
    if (randomNumber == 2)
        return new B;
    if (randomNumber == 3)
        return new C;
    return NULL;
}
static void identify(Base* p)
{
    //We dont know what subtype p can be, so we do this cast to see if it works;

    A* testA = dynamic_cast<A*>(p);
    B* testB = dynamic_cast<B*>(p);
    C* testC = dynamic_cast<C*>(p);
    char result = '0';

    if (testA)
        result = 'A';
    else if (testB)
        result = 'B';
    else if (testC)
        result = 'C';
    std::cout << "The type of object pointed by p is : " << result << std::endl;
}
static void identify(Base& p)
{  
    try 
    {
        A& test = dynamic_cast<A&>(p);
        std::cout << "The type of object referenced by p is : A" << std::endl;
        (void)test;
        return ;
    }
    catch (const std::exception &e)
    {}
    try 
    {
        B& test = dynamic_cast<B&>(p);
        std::cout << "The type of object referenced by p is : B" << std::endl;
        (void)test;
        return ;
    }
    catch (const std::exception &e)
    {}
    try 
    {
        C& test = dynamic_cast<C&>(p);
        std::cout << "The type of object referenced by p is : C" << std::endl;
        (void)test;
        return ;
    }
    catch (const std::exception &e)
    {}
    
    return ;
}
