#pragma once
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    //Constructors
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal& other);
    
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