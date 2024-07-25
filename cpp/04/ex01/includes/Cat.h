#pragma once
#include <iostream>
#include "Animal.h"
class Cat : public Animal
{
private:
    std::string type;
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
    std::string getType() const;

    //method
    void makeSound() const;
};

std::ostream    &operator<<(std::ostream &o, Cat const &fixed);