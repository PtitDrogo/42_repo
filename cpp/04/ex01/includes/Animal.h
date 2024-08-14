#pragma once
#include <iostream>
#include <string>


class Animal
{
protected:
    std::string type;

public:
    //Constructors
    Animal();
    Animal(std::string type);
    Animal(Animal& other);
    
    //Destructors
    virtual ~Animal();

    //Overloads
    Animal& operator=(const Animal& other);

    //Getters
    std::string getType() const;

    //method
    virtual void makeSound() const;
};

std::ostream    &operator<<(std::ostream &o, Animal const &fixed);