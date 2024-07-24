#pragma once
#include <iostream>
#include <string>
#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;
public:
    //Constructors
    DiamondTrap(const std::string& name);
    DiamondTrap(DiamondTrap& other);
    DiamondTrap();
    
    //Destructors
    virtual ~DiamondTrap();

    //Overloads
    DiamondTrap& operator=(const DiamondTrap& other);

    //Getters
    std::string get_name() const;
    
    //Method
    void attack(const std::string& target);
    void whoAmI();
};

std::ostream    &operator<<(std::ostream &o, DiamondTrap const &fixed);