#pragma once
#include <iostream>
#include <string>
#include "ClapTrap.h"
class ScavTrap : public ClapTrap
{
protected:
    std::string _name;
    int _hit_points;
    int _energy_points;
    int _attack_damage;
public:
    //Constructors
    ScavTrap(const std::string& _name) : ClapTrap(_name) {};
    ScavTrap(ScavTrap& other);
    // ScavTrap(std::string _name);
    ScavTrap();
    
    //Destructors
    ~ScavTrap();

    //Overloads
    ScavTrap& operator=(const ScavTrap& other);

    //Getters
    std::string get_name() const;
    int get_hp() const;
    int get_energy() const;
    int get_attack() const;

    //Method
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

std::ostream    &operator<<(std::ostream &o, ScavTrap const &fixed);