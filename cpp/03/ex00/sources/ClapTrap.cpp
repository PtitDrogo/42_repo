#include "ClapTrap.h"
#include <iostream>

static std::string s_logic(unsigned int amount, std::string word);

ClapTrap::ClapTrap() : 
    _name("no_name"), 
    _hit_points(10),
    _energy_points(10),
    _attack_damage(0) { std::cout << "Default constructor called for " << _name << std::endl; }
ClapTrap::ClapTrap(std::string _name) : 
    _name(_name),
    _hit_points(10), 
    _energy_points(10),
    _attack_damage(0) { std::cout << "Name constructor called for " << _name << std::endl; }
ClapTrap::ClapTrap(ClapTrap& other) : 
    _name(other.get_name()),
    _hit_points(other.get_hp()), 
    _energy_points(other.get_energy()),
    _attack_damage(other.get_attack()) { std::cout << "Copy constructor called for " << _name << std::endl; }
ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor called for " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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


std::string ClapTrap::get_name() const { return _name; }
int ClapTrap::get_hp() const { return _hit_points; }
int ClapTrap::get_energy() const { return _energy_points; }
int ClapTrap::get_attack() const { return _attack_damage; }

void ClapTrap::attack(const std::string& target)
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
void ClapTrap::takeDamage(unsigned int amount)
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
void ClapTrap::beRepaired(unsigned int amount)
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
}
static std::string s_logic(unsigned int amount, std::string word)
{
    if (amount == 1)
        return (word);
    return (word + "s");
}

std::ostream    &operator<<(std::ostream &out, ClapTrap const &fixed)
{
    out << fixed.get_name();
    return (out);
}