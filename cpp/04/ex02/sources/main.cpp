#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"
#include <iostream>

int main()
{
    //subject test
    std::cout << std::endl;
    {    
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        delete j;
        delete i;
    }
    //List of Animals
    std::cout << std::endl;
    {
        Animal* animals[10];
        
        for (int i = 0; i < 10; i++)
        {
            if (i <= 5)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        for (int i = 0; i < 10; i++)
        {
            delete animals[i];
        }
    }
    std::cout << std::endl;
    // what does a cat think about ?
    {
        Cat* miaousse = new Cat();
        std::cout << "Brain of cat : " << std::endl << *(miaousse->getBrain()) << std::endl;

        delete miaousse;
    }
    std::cout << std::endl;
    // deep copy test
   { 
        Dog basic;
        {
            std::cout << basic << std::endl;
            Dog tmp;
            tmp = basic;
            std::cout << tmp << std::endl;
            std::cout << "Brain address is " << tmp.getBrain() << " and its content are " << std::endl << *(tmp.getBrain());
            std::cout << std::endl;
            //tmp gets destroyed
        }
        std::cout << basic << std::endl;
        std::cout << "Brain address is " << basic.getBrain() << " and its content are " << std::endl << *(basic.getBrain());
    }
    std::cout << std::endl;
    // deep copy with pointer test
    {
        Cat *catthecat = new Cat();
        {
            Cat *tmp;
            tmp = catthecat;
            (void)tmp;
        }
        std::cout << std::endl;
        delete catthecat;
    }
    // Animal impossible_cat; 
    //Uncommenting the above will make the code not compile ! Since Animal is now abstract !
    // const Animal* j = new Animal();
    //Uncommenting the above will make the code not compile ! Since Animal is now abstract !

    return 0;
}
