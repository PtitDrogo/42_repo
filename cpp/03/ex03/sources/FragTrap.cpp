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
        std::cout << " (Terrible, terrible damage, Frag Style !)" << std::endl;
        _energy_points--;
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