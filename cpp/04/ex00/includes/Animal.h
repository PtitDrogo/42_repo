#pragma once
#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    //Constructors
    Animal();
    Animal(Animal& other);
    Animal(std::string type);
    
    //Destructors
    ~Animal();

    //Overloads
    Animal& operator=(const Animal& other);

    //Getters
    std::string getType() const;
};

std::ostream    &operator<<(std::ostream &o, Animal const &fixed);