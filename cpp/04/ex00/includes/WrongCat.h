#pragma once
#include <iostream>
#include "WrongAnimal.h"
class WrongCat : public WrongAnimal
{
public:
    //Constructors
    WrongCat();
    WrongCat(WrongCat& other);
    
    //Destructors
    ~WrongCat();

    //Overloads 
    WrongCat& operator=(const WrongCat& other);

    //Getters
    std::string getType() const;

    //method
    void makeSound() const;
};

std::ostream    &operator<<(std::ostream &o, WrongCat const &fixed);