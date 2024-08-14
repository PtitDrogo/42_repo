#include "Animal.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "Cat.h"
#include "Dog.h"
#include <iostream>

int main()
{
    {    
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        j->makeSound();
        i->makeSound(); //will output the cat sound!
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    std::cout << std::endl;
    //WrongAnimalTest
    {   
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the wrong cat sound!
        meta->makeSound();

        delete meta;
        delete i;
    }

    return 0;
}
