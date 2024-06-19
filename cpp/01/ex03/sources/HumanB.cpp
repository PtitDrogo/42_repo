#include "main.h"

void HumanB::attack(void)
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name) {}

HumanB::~HumanB() {}