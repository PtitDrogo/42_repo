#include "ScavTrap.h"
#include <iostream>

static std::string s_logic(unsigned int amount, std::string word);


ScavTrap::ScavTrap() : ClapTrap(), _is_in_guard_mode(false),
{  
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    
    std::cout << "ScavTrap Default constructor called for " << _name << std::endl; 
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), _is_in_guard_mode(false)
{
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap Name constructor called for " << _name << std::endl; 
}
ScavTrap::ScavTrap(ScavTrap& other) : ClapTrap(other), _is_in_guard_mode(false)
{
    std::cout << "ScavTrap Copy constructor called for " << _name << std::endl; 
}
ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap Destructor called for " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _is_in_guard_mode = other.get_status();
    }
    return (*this);
}

bool ScavTrap::get_status() const { return _is_in_guard_mode; }

void ScavTrap::attack(const std::string& target)
{
    if (_energy_points == 0)
    {
        std::cout << "Not enough energy to attack" << std::endl;
    }
    else
    {
        std::cout << _name << " attacks " << target << ", causing " << _attack_damage << " " << s_logic(_attack_damage, "point") << " of damage!";
        std::cout << " (whoah, that actually did something, Scav Power !)" << std::endl;
        _energy_points--;
    }
}

void ScavTrap::guardGate()
{
    _is_in_guard_mode = true;
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
void ScavTrap::stopGuard()
{
    _is_in_guard_mode = false;
    std::cout << "ScavTrap is now in Big Chilling mode." << std::endl;
}
static std::string s_logic(unsigned int amount, std::string word)
{
    if (amount == 1)
        return (word);
    return (word + "s");
}

std::ostream    &operator<<(std::ostream &out, ScavTrap const &fixed)
{
    out << fixed.get_name();
    return (out);
}