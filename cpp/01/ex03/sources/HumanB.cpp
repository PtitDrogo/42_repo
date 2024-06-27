#include "main.h"

void HumanB::attack(void)
{
    if (_weapon != NULL)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " attacks with their bare fists" << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
    _weapon = &Weapon;
}

HumanB::HumanB(std::string name) : _weapon(), _name(name) {}
    
HumanB::~HumanB() {}