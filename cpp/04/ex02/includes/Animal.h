#pragma once
#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    //Constructors
    Animal();
    Animal(const Animal& other);
    
    //Destructors
    virtual ~Animal();

    //Overloads
    Animal& operator=(const Animal& other);

    //Getters
    std::string getType() const;

    //method
    virtual void makeSound() const = 0;
};

std::ostream    &operator<<(std::ostream &o, Animal const &fixed);