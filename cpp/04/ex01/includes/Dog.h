#pragma once
#include <iostream>
#include "Animal.h"
#include "Brain.h"
class Dog : public Animal
{
private:
    Brain* _Brain;
public:
    //Constructors
    Dog();
    Dog(const Dog& other);
    
    //Destructors
    ~Dog();

    //Overloads 
    Dog& operator=(const Dog& other);

    //Getters
    Brain*      getBrain() const;

    //method
    void makeSound() const;
};

std::ostream    &operator<<(std::ostream &o, Dog const &fixed);