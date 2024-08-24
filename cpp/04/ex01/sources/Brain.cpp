#include "Brain.h"
#include <iostream>

Brain::Brain()
{
    for (int i = 0; i < 10; i++) 
    {
        ideas[i] = "Manger Boire Dormir";
    }
    std::cout << "Brain Default Constructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++) 
    {
        ideas[i] = other.ideas[i];
    } 
    std::cout << "Brain copy Constructor" << std::endl;
}
Brain::~Brain() 
{
    std::cout << "Brain Destructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignement operator" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++) 
        {
            ideas[i] = other.ideas[i];
        }
    }
    return (*this);
}
const std::string* Brain::getIdeas() const
{
    return (ideas);
}

std::ostream    &operator<<(std::ostream &out, Brain const &object)
{
    const std::string* tmp = object.getIdeas();

    for (int i = 0; i < 100; i++)
    {    
        if (!tmp[i].empty())
            out << tmp[i] << std::endl;
    }
    return (out);
}