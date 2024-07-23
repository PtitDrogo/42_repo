#include "DiamondTrap.h"
#include <iostream>

static std::string s_logic(unsigned int amount, std::string word);

DiamondTrap::DiamondTrap() : 
    ClapTrap("no_name_clap_name"), 
    ScavTrap(), 
    FragTrap(),
    _name("no_name")
{  
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
    std::cout << "DiamondTrap Default constructor called for " << _name << std::endl; 
}
DiamondTrap::DiamondTrap(const std::string& name) : 
    ClapTrap(name + "_clap_name"),
    ScavTrap(), 
    FragTrap(),
    _name(name)
{
    _hit_points = FragTrap::_hit_points;
    _energy_points = ScavTrap::_energy_points;
    _attack_damage = FragTrap::_attack_damage;
    std::cout << "DiamondTrap Name constructor called for " << _name << std::endl; 
}
DiamondTrap::DiamondTrap(DiamondTrap& other) : 
    ClapTrap(other), 
    ScavTrap(other), 
    FragTrap(other),
    _name(other.get_name())
{
    ClapTrap::_name = _name + "_clap_name";
    this->_hit_points = other.get_hp();
    this->_energy_points = other.get_energy();
    this->_attack_damage = other.get_attack();
    std::cout << "DiamondTrap Copy constructor called for " << _name << std::endl; 
}
DiamondTrap::~DiamondTrap() 
{   
    std::cout << "DiamondTrap Destructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}
std::string DiamondTrap::get_name() const { return _name; }

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
    std::cout << "Who am I ? Well that's easy, I am " << get_name() << " But my ClapTrap name is " << ClapTrap::_name << std::endl;
}
void DiamondTrap::takeDamage(unsigned int amount)
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
void DiamondTrap::beRepaired(unsigned int amount)
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
        std::cout << "(Not sure why DiamondTrap did that if he was full health ... )" << std::endl;
    }
}

static std::string s_logic(unsigned int amount, std::string word)
{
    if (amount == 1)
        return (word);
    return (word + "s");
}

std::ostream    &operator<<(std::ostream &out, DiamondTrap const &fixed)
{
    out << fixed.get_name();
    return (out);
}