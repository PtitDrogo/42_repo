#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"
#include <iostream>

int main()
{
    std::cout << std::endl << "Subject TEST " << std::endl;
    {    
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        delete j;
        delete i;
    }
    std::cout << std::endl << "ANIMAL LIST TEST " << std::endl;
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
    std::cout << std::endl << "What does a cat think about ? " << std::endl;
    {
        Cat* miaousse = new Cat();
        std::cout << "Brain of cat : " << std::endl << *(miaousse->getBrain()) << std::endl;

        delete miaousse;
    }
    std::cout << std::endl << "Deep Copy test " << std::endl;
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
    std::cout << std::endl << "Deep Copy test with pointer " << std::endl;
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
