#pragma once
#include <iostream>

class WrongAnimal
{
private:
    std::string type;

public:
    //Constructors
    WrongAnimal();
    WrongAnimal(WrongAnimal& other);
    
    //Destructors
    ~WrongAnimal();

    //Overloads
    WrongAnimal& operator=(const WrongAnimal& other);

    //Getters
    std::string getType() const;

    //method
    void makeSound() const;
};

std::ostream    &operator<<(std::ostream &o, WrongAnimal const &fixed);