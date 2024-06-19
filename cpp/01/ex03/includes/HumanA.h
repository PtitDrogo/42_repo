#ifndef HUMANA_H
# define HUMANA_H

#include "main.h"

class HumanA
{
private:
    Weapon      &_weapon;
    std::string _name;
public:
    void attack();
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
};

#endif