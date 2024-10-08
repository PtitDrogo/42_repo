#pragma once
#include <iostream>
#include "Animal.h"
#include "Brain.h"
class Cat : public Animal
{
private:
    std::string type;
    Brain* _Brain;
public:
    //Constructors
    Cat();
    Cat(const Cat& other);
    
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