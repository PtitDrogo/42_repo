#pragma once
#include <iostream>

class Brain
{
private:
    std::string ideas[100];

public:
    //Constructors
    Brain();
    Brain(Brain& other);
    
    //Destructors
    ~Brain();

    //Overloads
    Brain& operator=(const Brain& other);

    //Getters
    const std::string* getIdeas() const;
    //method
};

std::ostream    &operator<<(std::ostream &o, Brain const &fixed);