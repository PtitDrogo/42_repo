#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"
#include <iostream>

int main()
{
    //subject test
    // std::cout << std::endl;
    // {    
    //     const Animal* j = new Dog();
    //     const Animal* i = new Cat();
        
    //     delete j;//should not create a leak
    //     delete i;
    // }
    // std::cout << std::endl;
    //what does a cat think about ?
    // {
    //     Cat* miaousse = new Cat();
    //     std::cout << "Brain of cat : " << std::endl << *(miaousse->getBrain()) << std::endl;

    //     delete miaousse;
    // }
    std::cout << std::endl;
    // deep copy test
    Dog basic;
    {
        Dog tmp;
        tmp = basic;
    }
    std::cout << std::endl;
    // deep copy with pointer test
    // Cat *catthecat = new Cat();
    // {
    //     Cat *tmp;
    //     tmp = catthecat;
    // }
    // std::cout << std::endl;
    // delete catthecat;

    return 0;
}
