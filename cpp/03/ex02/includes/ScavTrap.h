#pragma once
#include <iostream>
#include <string>
#include "ClapTrap.h"
class ScavTrap : public ClapTrap
{
private:
    bool _is_in_guard_mode;

public:
    //Constructors
    ScavTrap(const std::string& name);
    ScavTrap(ScavTrap& other);
    ScavTrap();
    
    //Destructors
    ~ScavTrap();

    //Overloads
    ScavTrap& operator=(const ScavTrap& other);

    //Getters
    bool get_status() const;

    //Method
    void attack(const std::string& target);
    void guardGate();
    void stopGuard();
};

std::ostream    &operator<<(std::ostream &o, ScavTrap const &fixed);