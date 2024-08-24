#pragma once
#include <iostream>
#include "Animal.h"
class Dog : public Animal
{
public:
    //Constructors
    Dog();
    Dog(const Dog& other);
    
    //Destructors
    ~Dog();

    //Overloads
    Dog& operator=(const Dog& other);

    //Getters

    //method
    void makeSound() const;
};

std::ostream    &operator<<(std::ostream &o, Dog const &fixed);