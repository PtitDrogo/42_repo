#pragma once
#include <iostream>
#include "Animal.h"
#include "Brain.h"
class Cat : public Animal
{
private:
    Brain* _Brain;
public:
    //Constructors
    Cat();
    Cat(Cat& other);
    
    //Destructors
    ~Cat();

    //Overloads 
    Cat& operator=(const Cat& other);

    //Getters
    Brain*      getBrain() const;

    //method
    void makeSound() const;
};

std::ostream    &operator<<(std::ostream &o, Cat const &fixed);