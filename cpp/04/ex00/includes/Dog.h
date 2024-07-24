#pragma once
#include <iostream>
class Dog
{
private:
    int type;
    int _y;
public:
    //Constructors
    Dog();
    Dog(Dog& other);
    Dog(int a, int b);
    
    //Destructors
    ~Dog();

    //Overloads
    Dog& operator=(const Dog& other);

    //Getters
    int getX() const;
    int getY() const;
};

std::ostream    &operator<<(std::ostream &o, Dog const &fixed);