#pragma once
#include <iostream>

class Animal
{
private:
    std::string type;

public:
    //Constructors
    Animal();
    Animal(Animal& other);
    
    //Destructors
    virtual ~Animal();

    //Overloads
    Animal& operator=(const Animal& other);

    //Getters
    virtual std::string getType() const;

    //method
    virtual void makeSound() const;
};

std::ostream    &operator<<(std::ostream &o, Animal const &fixed);