#pragma once
#include <iostream>
#include <string>
class ClapTrap
{
protected:
    std::string _name;
    unsigned int _hit_points;
    unsigned int _energy_points;
    unsigned int _attack_damage;
public:
    //Constructors
    ClapTrap();
    ClapTrap(ClapTrap& other);
    ClapTrap(std::string _name);
    
    //Destructors
    ~ClapTrap();

    //Overloads
    ClapTrap& operator=(const ClapTrap& other);

    //Getters
    std::string get_name() const;
    unsigned int get_hp() const;
    unsigned int get_energy() const;
    unsigned int get_attack() const;

    //Method
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

std::ostream    &operator<<(std::ostream &o, ClapTrap const &fixed);