#pragma once
#include <iostream>
#include "Animal.h"
class Cat : public Animal
{
public:
    //Constructors
    Cat();
    Cat(const Cat& other);
    
    //Destructors
    ~Cat();

    //Overloads 
    Cat& operator=(const Cat& other);

    //Getters

    //method
    void makeSound() const;
};

std::ostream    &operator<<(std::ostream &o, Cat const &fixed);