#pragma once
#include <iostream>
#include "Animal.h"
class Dog : public Animal
{
public:
    //Constructors
    Dog();
    Dog(Dog& other);
    
    //Destructors
    ~Dog();

    //Overloads
    Dog& operator=(const Dog& other);

    //Getters
    std::string getType() const;

    //method
    void makeSound() const;
};

std::ostream    &operator<<(std::ostream &o, Dog const &fixed);