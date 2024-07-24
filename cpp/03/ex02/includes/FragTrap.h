#pragma once
#include <iostream>
#include <string>
#include "ClapTrap.h"
class FragTrap : public ClapTrap
{
public:
    //Constructors
    FragTrap(const std::string& name);
    FragTrap(FragTrap& other);
    FragTrap();
    
    //Destructors
    ~FragTrap();

    //Overloads
    FragTrap& operator=(const FragTrap& other);

    //Getters

    //Method
    void attack(const std::string& target);
    void highFivesGuys(void);
};

std::ostream    &operator<<(std::ostream &o, FragTrap const &fixed);