#pragma once
#include <iostream>
class Cat : public Animal
{
private:
    int type;
public:
    //Constructors
    Cat();
    Cat(Cat& other);
    Cat(std::string type);
    
    //Destructors
    ~Cat();

    //Overloads
    Cat& operator=(const Cat& other);

    //Getters
    int getX() const;
};

std::ostream    &operator<<(std::ostream &o, Cat const &fixed);