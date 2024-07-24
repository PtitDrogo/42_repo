#include "DiamondTrap.h"
#include <iostream>

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

std::ostream    &operator<<(std::ostream &out, DiamondTrap const &fixed)
{
    out << fixed.get_name();
    return (out);
}