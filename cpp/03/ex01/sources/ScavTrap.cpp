#include "ScavTrap.h"
#include <iostream>

static std::string s_logic(unsigned int amount, std::string word);


ScavTrap(const std::string& name) : ClapTrap(name) {};
ScavTrap::ScavTrap() : 
    _name("no_name"), 
    _hit_points(10),
    _energy_points(10),
    _attack_damage(0) { std::cout << "Default constructor called for " << _name << std::endl; }
ScavTrap::ScavTrap(std::string _name) : 
    _name(_name),
    _hit_points(10), 
    _energy_points(10),
    _attack_damage(0) { std::cout << "Name constructor called for " << _name << std::endl; }
ScavTrap::ScavTrap(ScavTrap& other) : 
    _name(other.get_name()),
    _hit_points(other.get_hp()), 
    _energy_points(other.get_energy()),
    _attack_damage(other.get_attack()) { std::cout << "Copy constructor called for " << _name << std::endl; }
ScavTrap::~ScavTrap() 
{
    std::cout << "Destructor called for " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        this->_name = get_name();
        this->_hit_points = get_hp();
        this->_energy_points = get_energy();
        this->_attack_damage = get_attack();
    }
    return (*this);
}


std::string ScavTrap::get_name() const { return _name; }
int ScavTrap::get_hp() const { return _hit_points; }
int ScavTrap::get_energy() const { return _energy_points; }
int ScavTrap::get_attack() const { return _attack_damage; }

void ScavTrap::attack(const std::string& target)
{
    if (_energy_points == 0)
    {
        std::cout << "Not enough energy to attack" << std::endl;
    }
    else
    {
        std::cout << _name << " attacks " << target << ", causing " << _attack_damage << " " << s_logic(_attack_damage, "point") << " of damage!" << std::endl;
        _energy_points--;
    }
}
void ScavTrap::takeDamage(unsigned int amount)
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
void ScavTrap::beRepaired(unsigned int amount)
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
        std::cout << "(Not sure why ScavTrap did that if he was full health ... )" << std::endl;
    }
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