#include "FragTrap.h"
#include <iostream>

static std::string s_logic(unsigned int amount, std::string word);

FragTrap::FragTrap() : ClapTrap()
{  
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    
    std::cout << "FragTrap Default constructor called for " << _name << std::endl; 
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "FragTrap Name constructor called for " << _name << std::endl; 
}
FragTrap::FragTrap(FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called for " << _name << std::endl; 
}
FragTrap::~FragTrap() 
{   
    std::cout << "FragTrap Destructor called for " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (_energy_points == 0)
    {
        std::cout << "Not enough energy to attack" << std::endl;
    }
    else
    {
        std::cout << _name << " attacks " << target << ", causing " << _attack_damage << " " << s_logic(_attack_damage, "point") << " of damage!";
        std::cout << " (Terrible, terrible damage)" << std::endl;
        _energy_points--;
    }
}
void FragTrap::takeDamage(unsigned int amount)
{
    std::cout << _name << " takes " << amount << " " << s_logic(amount, "point") << " of damage!" << std::endl;
    if (_hit_points > 0 && (_hit_points <= static_cast<int>(amount)))
    {
        std::cout << _name << " died from his wounds " << std::endl;
    }
    else if (_hit_points < 0)
    {
        std::cout << _name << " was already dead " << std::endl;
    }
    _hit_points -= amount;
}
void FragTrap::beRepaired(unsigned int amount)
{
    if (_energy_points == 0)
    {
        std::cout << "Not enough energy to repair" << std::endl;
    }
    else 
    {
        if (_hit_points + amount >= 10)
        {
            amount = 10 - _hit_points;
        }
        std::cout << _name << " repairs " << amount << " health " << s_logic(amount, "point") << " !" << std::endl;
        _energy_points--;
        _hit_points += amount;
    }
    if (amount == 0)
    {
        std::cout << "(Not sure why FragTrap did that if he was full health ... )" << std::endl;
    }
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "What a beautiful day to be alive right guys ? High Five !" << std::endl;
}

static std::string s_logic(unsigned int amount, std::string word)
{
    if (amount == 1)
        return (word);
    return (word + "s");
}

std::ostream    &operator<<(std::ostream &out, FragTrap const &fixed)
{
    out << fixed.get_name();
    return (out);
}